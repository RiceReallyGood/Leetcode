// Nonrecursive
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> visited;
        vector<TreeNode *> nodestack;
        TreeNode *p = root;
        while (!nodestack.empty() || p)
        {
            while (p)
            {
                nodestack.push_back(p);
                p = p->left;
            }
            p = nodestack.back();
            nodestack.pop_back();
            visited.push_back(p->val);
            p = p->right;
        }
        return visited;
    }
};