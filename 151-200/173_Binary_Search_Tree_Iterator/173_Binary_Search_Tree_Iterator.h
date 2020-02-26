#include <stack>
using namespace std;

#define NULL nullptr
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root) { pushleft(root); }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *p = path.top();
        path.pop();
        pushleft(p->right);
        return p->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !path.empty(); }

private:
    void pushleft(TreeNode *root)
    {
        while (root)
        {
            path.push(root);
            root = root->left;
        }
    }
    stack<TreeNode *> path;
};