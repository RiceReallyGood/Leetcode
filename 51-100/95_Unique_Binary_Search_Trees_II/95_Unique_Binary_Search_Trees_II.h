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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return Trees(1, n);
    }

    vector<TreeNode *> Trees(int begin, int end)
    {
        if (begin == end)
            return {new TreeNode(begin)};
        if (begin > end)
            return {NULL};
        vector<TreeNode *> ret;
        for (int rootval = begin; rootval <= end; rootval++)
        {
            vector<TreeNode *> lefttrees = Trees(begin, rootval - 1);
            vector<TreeNode *> righttrees = Trees(rootval + 1, end);
            for (TreeNode *lefttree : lefttrees)
                for (TreeNode *righttree : righttrees)
                {
                    TreeNode *root = new TreeNode(rootval);
                    root->left = lefttree;
                    root->right = righttree;
                    ret.push_back(root);
                }
        }
        return ret;
    }
};