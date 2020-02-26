#include <queue>
#include <string>
#include <sstream>
using namespace std;

#define NULL nullptr
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream ret;
        if (!root)
            return ret.str();
        queue<TreeNode *> nodeq;
        nodeq.push(root);
        ret << root->val;
        TreeNode *p;
        while (!nodeq.empty()){
            p = nodeq.front();
            nodeq.pop();
            if (p->left){
                nodeq.push(p->left);
                ret << "," << p->left->val;
            }
            else
                ret << ","<< "null";
            if (p->right){
                nodeq.push(p->right);
                ret << "," << p->right->val;
            }
            else
                ret << ","<< "null";
        }
        return ret.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.empty())
            return nullptr;
        queue<TreeNode*> nodeq;
        int l = 0, r = 0;
        for(; r < data.size(); r++){
            if(data[r] == ','){
                nodeq.push(ToTreeNode(data.substr(l, r - l)));
                l = r + 1;
            }
        }
        nodeq.push(ToTreeNode(data.substr(l, r - l)));

        TreeNode *root = nodeq.front();
        queue<TreeNode*> levelq;
        levelq.push(nodeq.front());
        nodeq.pop();
        TreeNode* p;
        while(!nodeq.empty()){
            for(int i = 0; i < levelq.size(); i++){
                p = levelq.front();
                levelq.pop();
                p->left = nodeq.front();
                if(nodeq.front())
                    levelq.push(nodeq.front());
                nodeq.pop();
                p->right = nodeq.front();
                if(nodeq.front())
                    levelq.push(nodeq.front());
                nodeq.pop();
            }
        }
        return root;
    }

    TreeNode *ToTreeNode(const string& s){
        if(s == "null")
            return nullptr;
        return new TreeNode(stoi(s));
    }
};