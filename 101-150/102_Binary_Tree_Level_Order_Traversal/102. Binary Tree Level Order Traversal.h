#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;

        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        while (!nodequeue.empty())
        {
            int currlevelnum = nodequeue.size();
            vector<int> currlevelvals;
            for (int i = 0; i < currlevelnum; i++)
            {
                TreeNode *p = nodequeue.front();
                currlevelvals.push_back(p->val);
                nodequeue.pop();
                if (p->left)
                    nodequeue.push(p->left);

                if (p->right)
                    nodequeue.push(p->right);
            }
            ret.push_back(currlevelvals);
        }
        return ret;
    }
};