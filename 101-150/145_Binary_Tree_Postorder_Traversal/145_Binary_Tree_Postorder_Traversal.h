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

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<pair<TreeNode *, bool>> nodestack;
        TreeNode *p = root;
        pair<TreeNode *, bool> nodewithstate;

        while (!nodestack.empty() || p)
        {
            while (p)
            {
                nodestack.push({p, false});
                p = p->left;
            }
            nodewithstate = nodestack.top();
            nodestack.pop();

            if (!(nodewithstate.second))
            {
                nodewithstate.second = true;
                nodestack.push(nodewithstate);
                p = nodewithstate.first->right;
            }
            else
            {
                ret.push_back(nodewithstate.first->val);
                p = nullptr;
            }
        }
    }
};