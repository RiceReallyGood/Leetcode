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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        vector<vector<int>> paths;
        if (root)
            Rec(root, sum, path, paths);
        return paths;
    }

private:
    void Rec(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &paths)
    {
        path.push_back(root->val);
        int rest = sum - root->val;
        if (!root->left && !root->right)
        {
            if (rest == 0)
                paths.push_back(path);
        }

        if (root->left)
            Rec(root->left, rest, path, paths);

        if (root->right)
            Rec(root->right, rest, path, paths);

        path.pop_back();
    }
};