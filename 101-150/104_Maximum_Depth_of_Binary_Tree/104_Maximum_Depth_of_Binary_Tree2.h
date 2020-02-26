#include <vector>
#include <stack>
using namespace std;
//iterative

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        stack<pair<TreeNode *, int>> nodestack;
        nodestack.push({root, 1});

        int maxdepth = 0;
        while (!nodestack.empty())
        {
            auto curr = nodestack.top();
            nodestack.pop();
            maxdepth = max(curr.second, maxdepth);
            if ((curr.first)->right)
                nodestack.push({(curr.first)->right, curr.second + 1});
            if ((curr.first)->left)
                nodestack.push({(curr.first)->left, curr.second + 1});
        }
        return maxdepth;
    }
};