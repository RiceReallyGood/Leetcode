#include <algorithm>
using namespace std;
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
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

private:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftheight = height(root->left);
        if (leftheight == -1)
            return -1;
        int rightheight = height(root->right);
        if (rightheight == -1)
            return -1;

        if (abs(leftheight - rightheight) > 1)
            return -1;

        return max(leftheight, rightheight) + 1;
    }
};