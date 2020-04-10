
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        TreeNode* curr = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        curr->left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
        curr->right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);
        return curr;
    }
};

class Solution{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};