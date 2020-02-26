#include <vector>
using namespace std;
//recursuve

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode *buildTree(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2)
    {
        if (l1 == r1)
            return NULL;

        TreeNode *root = new TreeNode(preorder[l1]);

        int rootindex = 0;
        while (rootindex < r2)
        {
            if (inorder[rootindex] == preorder[l1])
                break;
            rootindex++;
        }

        int lefttreenum = rootindex - l2;
        root->left = buildTree(preorder, l1 + 1, l1 + lefttreenum + 1, inorder, l2, rootindex);
        root->right = buildTree(preorder, l1 + lefttreenum + 1, r1, inorder, rootindex + 1, r2);
        return root;
    }
};