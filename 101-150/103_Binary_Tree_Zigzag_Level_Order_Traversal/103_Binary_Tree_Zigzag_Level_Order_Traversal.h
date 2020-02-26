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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;

        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        bool lefttoright = true;
        while (!nodequeue.empty())
        {
            int currlevelnum = nodequeue.size();
            vector<int> vals(currlevelnum);
            for (int i = 0; i < currlevelnum; i++)
            {
                TreeNode *p = nodequeue.front();
                nodequeue.pop();
                vals[lefttoright ? i : currlevelnum - i - 1] = p->val;
                if (p->left)
                    nodequeue.push(p->left);
                if (p->right)
                    nodequeue.push(p->right);
            }
            ret.push_back(vals);
            lefttoright = !lefttoright;
        }
        return ret;
    }
};