#include <vector>
#include <string>
#include <sstream>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> paths;
        if (!root)
            return paths;

        binaryTreePaths(root, path, paths);
        return paths;
    }

private:
    void binaryTreePaths(TreeNode *root, vector<int> &path, vector<string> &paths)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
            paths.push_back(vector2string(path));

        if (root->left)
            binaryTreePaths(root->left, path, paths);
        if (root->right)
            binaryTreePaths(root->right, path, paths);

        path.pop_back();
    }

    string vector2string(vector<int> &path)
    {
        ostringstream ret;
        if (path.empty())
            return ret.str();
        for (int i = 0; i < path.size() - 1; i++)
            ret << path[i] << "->";

        ret << path.back();
        return ret.str();
    }
};