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
    vector<int> findMode(TreeNode* root) {
        int count = 0, maxcount = 0;
        int prevvalue = INT_MIN;
        vector<int> ret;
        dfs(root, prevvalue, count, maxcount, ret);
        return ret;
    }

private:
    void dfs(TreeNode* root, int& prevvalue, int& count, int& maxcount, vector<int>& candidates){
        if(root){
            dfs(root->left, prevvalue, count, maxcount, candidates);
            if(prevvalue == root->val)
                count++;
            else
                count = 1;
            
            if(count == maxcount){
                candidates.push_back(root->val);
            }
            else if(count > maxcount){
                maxcount = count;
                candidates.clear();
                candidates.push_back(root->val);
            }
            prevvalue = root->val;
            dfs(root->right, prevvalue, count, maxcount, candidates);
        }
    }
};