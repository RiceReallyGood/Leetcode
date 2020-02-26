#define NULL nullptr
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        return Rec(root, sum);
    }

private:
    bool Rec(TreeNode *root, int sum)
    {
        int restnum = sum - root->val;
        if (!root->left)
        {
            if (!root->right)
                return restnum == 0;
            else
                return Rec(root->right, restnum);
        }
        else
        {
            if (!root->right)
                return Rec(root->left, restnum);
            else
                return Rec(root->left, restnum) || Rec(root->right, restnum);
        }
    }
};