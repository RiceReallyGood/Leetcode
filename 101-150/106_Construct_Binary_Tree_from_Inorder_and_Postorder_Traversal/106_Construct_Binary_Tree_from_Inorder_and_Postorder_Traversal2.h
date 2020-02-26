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

        int postorderindex = postorder.size();

        return buildTree(val_index, postorder, 0, inorder.size(), postorderindex);
    }

private:
    TreeNode *buildTree(unordered_map<int, int> &val_index, vector<int> &postorder, int inl, int inr, int &postorderindex)
    {
        if (inl == inr)
            return NULL;

        int curr = postorder[--postorderindex];
        TreeNode *root = new TreeNode(curr);
        root->right = buildTree(val_index, postorder, val_index[curr] + 1, inr, postorderindex);
        root->left = buildTree(val_index, postorder, inl, val_index[curr], postorderindex);
        return root;
    }
};