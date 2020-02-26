// Recursive
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> visited;
        inorderTraversal(root, visited);
        return visited;
    }

    void inorderTraversal(TreeNode *root, vector<int> &visited)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left, visited);
        visited.push_back(root->val);
        inorderTraversal(root->right, visited);
    }
};