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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;
        rightSideView(root, 1, view);
        return view;
    }

private:
    void rightSideView(TreeNode *root, int level, vector<int> &view)
    {
        if (!root)
            return;
        if (view.size() < level)
            view.push_back(root->val);

        rightSideView(root->right, level + 1, view);
        rightSideView(root->left, level + 1, view);
    }
};