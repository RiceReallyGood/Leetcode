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
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;

        int path = 0;
        int ret = 0;

        Root2LeafNums(root, path, ret);
        return ret;
    }

private:
    void Root2LeafNums(TreeNode *root, int &path, int &sum)
    {
        path = path * 10 + root->val;
        if (!root->left && !root->right)
            sum += path;

        if (root->left)
            Root2LeafNums(root->left, path, sum);

        if (root->right)
            Root2LeafNums(root->right, path, sum);

        path /= 10;
    }
};