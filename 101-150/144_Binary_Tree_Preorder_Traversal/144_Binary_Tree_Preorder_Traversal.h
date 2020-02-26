#include <stack>
#include <vector>
using namespace std;

#define NULL nullptr
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> nodestack;
        TreeNode *p = root;
        while (!nodestack.empty() || p)
        {
            while (p)
            {
                ret.push_back(p->val);
                nodestack.push(p);
                p = p->left;
            }
            p = nodestack.top();
            nodestack.pop();
            p = p->right;
        }
        return ret;
    }
};

class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> nodestack;
        if (root)
            nodestack.push(root);
        TreeNode *p = nullptr;
        while (!nodestack.empty())
        {
            p = nodestack.top();
            nodestack.pop();
            ret.push_back(p->val);
            if (p->right)
                nodestack.push(p->right);
            if (p->left)
                nodestack.push(p->left);
        }
        return ret;
    }
};