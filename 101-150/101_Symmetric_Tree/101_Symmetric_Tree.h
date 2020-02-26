#include <vector>
using namespace std;

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
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }

private:
    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL)
            return root1 == root2;

        return root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};