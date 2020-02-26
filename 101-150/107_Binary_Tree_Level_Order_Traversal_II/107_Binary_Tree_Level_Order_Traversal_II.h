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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        while (!nodequeue.empty())
        {
            int thislevelnum = nodequeue.size();
            vector<int> vals;
            for (int i = 0; i < thislevelnum; i++)
            {
                TreeNode *curr = nodequeue.front();
                nodequeue.pop();
                vals.push_back(curr->val);
                if (curr->left)
                    nodequeue.push(curr->left);
                if (curr->right)
                    nodequeue.push(curr->right);
            }
            ret.push_back(vals);
        }

        for (int i = 0, j = ret.size() - 1; i < j; i++, j--)
            ret[i].swap(ret[j]);

        return ret;
    }
};