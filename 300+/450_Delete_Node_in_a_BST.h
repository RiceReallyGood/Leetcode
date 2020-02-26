#include <climits>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** p = &root;
        TreeNode* curr = root;
        //find it
        while(curr && curr->val != key){
            if(curr->val > key){
                p = &(curr->left);
                curr = curr->left;
            }
            else{
                p = &(curr->right);
                curr = curr->right;
            }
        }
        if(!curr)
            return root;
        if(!curr->left){
            *p = curr->right;
            delete curr;
            return root;
        }
        else if(!curr->right){
            *p = curr->left;
            delete curr;
            return root;
        }
        TreeNode *knode = curr;
        p = &(curr->right);
        curr = curr->right;
        while(curr->left){
            p = &(curr->left);
            curr = curr->left;
        }
        knode->val = curr->val;
        *p = curr->right;
        delete curr;
        return root;
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else{ //root->val == key
            if(!root->left){
                auto tmp = root;
                root = root->right;
                delete tmp;
            }
            else if(!root->right){
                auto tmp = root;
                root = root->left;
                delete tmp;
            }
            else{
                int Successor = 0;
                root->right = deletMin(root->right, Successor);
                root->val = Successor;
            }
        }
        return root;
    }

private:
    TreeNode* deletMin(TreeNode *root, int &value){
        TreeNode** p = &root;
        TreeNode* node = root;
        while(node->left){
            p = &(node->left);
            node = node->left;
        }
        value = node->val;
        *p = node->right;
        delete node;
        return root;
    }
};