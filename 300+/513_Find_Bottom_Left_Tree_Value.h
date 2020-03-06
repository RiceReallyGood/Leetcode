#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> leftleaves;
        recurse(root, 1, leftleaves);
        return leftleaves.back();
    }

private:
    void recurse(TreeNode* root, int height, vector<int>&leftleaves){
        if(root){
            if(height > leftleaves.size()) leftleaves.push_back(root->val);
            recurse(root->left, height + 1, leftleaves);
            recurse(root->right, height + 1, leftleaves);
        }
    }
};