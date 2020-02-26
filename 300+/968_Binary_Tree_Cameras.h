#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        vector<int> withcamera(1001);
        vector<int> nocamera(1001);
        vector<int> unwatch(1001);
        withcamera[0] = INT_MAX;
        nocamera[0] = 0;
        unwatch[0] = 0;
        int count = 0;
        MonitorTree(root, withcamera, nocamera, unwatch, count);
        return min(withcamera[count], nocamera[count]);
    }

private:
    void MonitorTree(TreeNode* root, vector<int>& withcamera, vector<int>& nocamera, vector<int>& unwatch, int &index){
        if(!root) return;
        MonitorTree(root->left, withcamera, nocamera, unwatch, index);
        MonitorTree(root->right, withcamera, nocamera, unwatch, index);
        ++index;
        root->val = index;
        int lindex = root->left == nullptr ? 0 : root->left->val;
        int rindex = root->right == nullptr ? 0 : root->right->val;
        /* int temp = min(withcamera[lindex], min(nocamera[lindex], unwatch[lindex]))
                + min(withcamera[rindex], min(nocamera[rindex], unwatch[rindex]));
        withcamera.push_back(temp + 1);
        temp = INT_MAX;
        if(lindex != 0)
            temp = withcamera[lindex] + min(withcamera[rindex], nocamera[rindex]);
        if(rindex != 0)
            temp = min(temp, withcamera[rindex] + min(withcamera[lindex], nocamera[lindex]));
        nocamera.push_back(temp);

        if(nocamera[lindex] == INT_MAX || nocamera[rindex] == INT_MAX)
            unwatch.push_back(INT_MAX);
        else
            unwatch.push_back(nocamera[lindex] + nocamera[rindex]); */
        if(lindex == 0){
            if(rindex == 0){
                withcamera[index] = 1;
                nocamera[index] = INT_MAX;
                unwatch[index] = 0;
            } 
            else{
                withcamera[index] = 1 + min(withcamera[rindex], min(nocamera[rindex], unwatch[rindex]));
                nocamera[index] = withcamera[rindex];
                unwatch[index] = nocamera[rindex];
            }
        }
        else{
            if(rindex == 0){
                withcamera[index] = 1 + min(withcamera[lindex], min(nocamera[lindex], unwatch[lindex]));
                nocamera[index] = withcamera[lindex];
                unwatch[index] = nocamera[lindex];
            } 
            else{
                withcamera[index] = 1 + min(withcamera[lindex], min(nocamera[lindex], unwatch[lindex]))
                                          + min(withcamera[rindex], min(nocamera[rindex], unwatch[rindex]));
                nocamera[index] = min(withcamera[lindex] + min(withcamera[rindex], nocamera[rindex]),
                                          withcamera[rindex] + min(withcamera[lindex], nocamera[lindex]));
                if(nocamera[lindex] == INT_MAX || nocamera[rindex] == INT_MAX)
                    unwatch[index] = INT_MAX;
                else
                    unwatch[index] = nocamera[lindex] + nocamera[rindex];
            }
        }
    }
};