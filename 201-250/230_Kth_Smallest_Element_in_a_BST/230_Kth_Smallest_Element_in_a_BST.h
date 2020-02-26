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

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int visited = 0;
        TreeNode *p = root;
        stack<TreeNode *> nodestack;

        while (!nodestack.empty() || p)
        {
            while (p)
            {
                nodestack.push(p);
                p = p->left;
            }

            p = nodestack.top();
            nodestack.pop();
            visited++;
            if (visited == k)
                return p->val;
            p = p->right;
        }
    }
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int res;
        findkthSmallest(root, k, res);
        return res;
    }

private:
    bool findkthSmallest(TreeNode *root, int &tovisit, int &res)
    {
        if (!root)
            return false;

        if (findkthSmallest(root->left, tovisit, res))
            return true;

        if (--tovisit == 0)
        {
            res = root->val;
            return true;
        }

        return findkthSmallest(root->right, tovisit, res);
    }
};