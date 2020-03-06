#include <string>
#include <cstring>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rec1(root, ret);
        return ret;
    }

    void rec1(TreeNode* root, string& ser){
        if(root){
            ser += to_string(root->val) + ",";
            rec1(root->left, ser);
            rec1(root->right, ser);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return rec2(data, INT_MAX, index);
    }

    TreeNode*  rec2(string& data, int rightbound, int& index){
        if(index == data.size()) return nullptr;
        int e = index;
        while(data[e] != ',') e++;
        int v = stoi(data.substr(index, e - index));
        if(v <= rightbound){
            index = e + 1;
            TreeNode *node = new TreeNode(v);
            node->left = rec2(data, v, index);
            node->right = rec2(data, rightbound, index);
            return node;
        }
        return nullptr;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rec1(root, ret);
        return ret;
    }

    void rec1(TreeNode* root, string& ser){
        static char buff[sizeof(int)];
        if(root){
            memcpy(buff, &(root->val), sizeof(int));
            for(int i = 0; i < sizeof(int); i++)
                ser.push_back(buff[i]);
            rec1(root->left, ser);
            rec1(root->right, ser);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return rec2(data, INT_MAX, index);
    }

    TreeNode*  rec2(string& data, int rightbound, int& index){
        if(index == data.size()) return nullptr;
        int v;
        memcpy(&v, &data[index], sizeof(int));
        if(v <= rightbound){
            TreeNode *node = new TreeNode(v);
            index += sizeof(int);
            node->left = rec2(data, v, index);
            node->right = rec2(data, rightbound, index);
            return node;
        }
        return nullptr;
    }
};