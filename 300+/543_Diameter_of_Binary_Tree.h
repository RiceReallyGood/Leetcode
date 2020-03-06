#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0, diameter = 0;
        recurse(root, height, diameter);
        return diameter;
    }

private:
    void recurse(TreeNode *root, int& height, int& diameter){
        if(!root){
            height = diameter = 0;
            return;
        }
        int leftheight = 0, rightheight = 0;
        int leftdiameter = 0, rightdiameter = 0;
        recurse(root->left, leftheight, leftdiameter);
        recurse(root->right, rightheight, rightdiameter);
        height = std::max(leftheight, rightheight) + 1;
        diameter = std::max(std::max(leftdiameter, rightdiameter) , leftheight + rightheight);
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        TreeHeight(root, diameter);
        return diameter;
    }

private:
    int TreeHeight(TreeNode *root, int& diameter){
        if(!root) return 0;
        int leftheight = TreeHeight(root->left, diameter);
        int rightheight = TreeHeight(root->right, diameter);
        diameter = std::max(diameter, leftheight + rightheight);
        return 1 + std::max(leftheight, rightheight);
    }
};