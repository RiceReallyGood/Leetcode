struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
       return recurse(root, false); 
    }

private:
    int recurse(TreeNode* root, bool isleft){
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr){
            if(isleft)
                return root->val;
            else
                return 0;
        }
        
        return recurse(root->left, true) + recurse(root->right, false);
    }
};