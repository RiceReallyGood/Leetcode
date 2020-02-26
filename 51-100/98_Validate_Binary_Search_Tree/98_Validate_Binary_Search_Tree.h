#define NULL nullptr
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
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        TreeNode *p = root;
        vector<TreeNode *> nodestack;
        int lastval;
        while (p)
        {
            nodestack.push_back(p);
            p = p->left;
        }
        p = nodestack.back();
        nodestack.pop_back();
        lastval = p->val;
        p = p->right;
        while (!nodestack.empty() || p)
        {
            while (p)
            {
                nodestack.push_back(p);
                p = p->left;
            }
            p = nodestack.back();
            nodestack.pop_back();
            if (p->val <= lastval)
                return false;
            lastval = p->val;
            p = p->right;
        }
        return true;
    }
};