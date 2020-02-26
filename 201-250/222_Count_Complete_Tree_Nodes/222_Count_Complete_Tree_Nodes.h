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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int MaxLevel = 0;
        int LastLevelNums = 0;
        TreeNode *p = root;
        while (p)
        {
            p = p->left;
            MaxLevel++;
        }

        p = root;
        int level = 0;
        stack<pair<TreeNode *, int>> NodeStack;
        while (!NodeStack.empty() || p)
        {
            while (p)
            {
                NodeStack.push(make_pair(p, level));
                p = p->left;
                level++;
            }

            if (level != MaxLevel)
                break;

            LastLevelNums++;

            NodeStack.pop();

            if (!NodeStack.empty())
            {
                p = NodeStack.top().first;
                level = NodeStack.top().second;
                NodeStack.pop();
            }
        }

        return (1 << (MaxLevel - 1)) - 1 + LastLevelNums;
    }
};

class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        int lh = height(root, true);
        int rh = height(root, false);
        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int height(TreeNode *root, bool left)
    {
        int h = 0;
        while (root)
        {
            if (left)
                root = root->left;
            else
                root = root->right;

            h++;
        }
        return h;
    }
};