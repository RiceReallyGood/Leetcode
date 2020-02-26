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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < inorder.size(); i++)
            hashmap[inorder[i]] = i;
        int preorderindex = 0;
        return buildTree(preorder, hashmap, 0, inorder.size(), preorderindex);
    }

private:
    TreeNode *buildTree(vector<int> &preorder, unordered_map<int, int> &hashmap, int l, int r, int &preorderindex)
    {
        if (l == r)
            return NULL;

        int currval = preorder[preorderindex++];
        TreeNode *root = new TreeNode(currval);
        root->left = buildTree(preorder, hashmap, l, hashmap[currval], preorderindex);
        root->right = buildTree(preorder, hashmap, hashmap[currval] + 1, r, preorderindex);
        return root;
    }
};