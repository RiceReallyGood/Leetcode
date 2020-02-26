#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return rob(root, false);
    }

private:
    int rob(TreeNode* node, bool robparent){
        if(node == nullptr)
            return 0;
        
        int norob = 0;
        if(unrobmax.find(node) != unrobmax.end())
            norob = unrobmax[node];
        else{
            norob= rob(node->left, false) + rob(node->right, false);
            unrobmax[node] = norob;
        }
        if(robparent)
            return norob;
        
        int dorob = 0;
        if(robmax.find(node) != robmax.end())
            dorob = robmax[node];
        else{
            dorob = node->val + rob(node->left, true) + rob(node->right, true);
            robmax[node] = dorob;
        }

        return max(norob, dorob);
    }

    unordered_map<TreeNode*, int> unrobmax;
    unordered_map<TreeNode*, int> robmax;
};

class Solution {
public:
    int rob(TreeNode* root) {
        int unrobmax = 0, robmax = 0;
        rob(root, unrobmax, robmax);
        return max(robmax, unrobmax);
    }

private:
    void rob(TreeNode *node, int& unrobmax, int& robmax){
        if(node == nullptr){
            unrobmax = robmax = 0;
            return;
        }

        int leftunrobmax = 0, rightunrobmax = 0;
        int leftrobmax = 0, rightrobmax = 0;
        rob(node->left, leftunrobmax, leftrobmax);
        rob(node->right, rightunrobmax, rightrobmax);
        unrobmax = max(leftrobmax, leftunrobmax) + max(rightrobmax, rightunrobmax);
        robmax  = node->val + leftunrobmax + rightunrobmax;
    }
};