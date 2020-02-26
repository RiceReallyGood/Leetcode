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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        int mindepth = 0;
        while (!nodequeue.empty())
        {
            mindepth++;
            int currlevelnum = nodequeue.size();
            for (int i = 0; i < currlevelnum; i++)
            {
                TreeNode *curr = nodequeue.front();
                nodequeue.pop();

                if (!curr->left)
                {
                    if (curr->right)
                        nodequeue.push(curr->right);
                    else
                        return mindepth;
                }
                else
                {
                    nodequeue.push(curr->left);
                    if (curr->right)
                        nodequeue.push(curr->right);
                }
            }
        }
        return mindepth;
    }
};