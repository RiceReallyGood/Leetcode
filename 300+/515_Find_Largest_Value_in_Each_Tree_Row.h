#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ret;
        while(!q.empty()){
            int levelcount = q.size();
            int levelmax = INT_MIN;
            for(int i = 0; i < levelcount; i++){
                TreeNode *node = q.front();
                q.pop();
                levelmax = max(levelmax, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(levelmax);
        }
        return ret;
    }
};