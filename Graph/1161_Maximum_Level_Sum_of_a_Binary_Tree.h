#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int maxsum = 0, maxlevel;
        while(!q.empty()){
            level++;
            int currlevelsize = q.size();
            int levelsum = 0;
            for(int i = 0; i < currlevelsize; i++){
                TreeNode* node = q.front();
                q.pop();
                levelsum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(levelsum > maxsum){
                maxsum = levelsum;
                maxlevel = level;
            }
        }
        return maxlevel;
    }
};