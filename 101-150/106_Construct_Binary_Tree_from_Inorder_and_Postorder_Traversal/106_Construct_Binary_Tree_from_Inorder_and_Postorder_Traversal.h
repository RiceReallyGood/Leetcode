#include <vector>
#include <unordered_map>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> val_index;
        for (int i = 0; i < inorder.size(); i++)
            val_index[inorder[i]] = i;

        return buildTree(val_index, postorder, 0, inorder.size(), 0, postorder.size());
    }

private:
    TreeNode *buildTree(unordered_map<int, int> &val_index, vector<int> &postorder, int inl, int inr, int postl, int postr)
    {
        if (inl == inr)
            return NULL;

        int curr = postorder[postr - 1];
        TreeNode *root = new TreeNode(curr);
        int currindex = val_index[curr];
        root->left = buildTree(val_index, postorder, inl, currindex, postl, postl + currindex - inl);
        root->right = buildTree(val_index, postorder, currindex + 1, inr, postl + currindex - inl, postr - 1);
        return root;
    }
};