#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int mindiff = INT_MAX;
        inorder(root, prev, mindiff);
        return mindiff;
    }

private:
    void inorder(TreeNode* root, int& prev, int& mindiff){
        if(!root) return;
        inorder(root->left, prev, mindiff);
        if(prev != -1)
            mindiff = std::min(mindiff, root->val - prev);
        prev = root->val;
        inorder(root->right, prev, mindiff);
    }
};