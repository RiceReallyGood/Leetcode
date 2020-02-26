#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<Node*> q;
        q.push(root);
        Node *node;
        vector<int> level;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                node = q.front();
                q.pop();
                level.push_back(node->val);
                for(Node* nd : node->children)
                    q.push(nd);
            }
            ret.push_back(level);
            level.clear();
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<Node*> q;
        q.push(root);
        Node *node;
        vector<int> level;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto &nd : node->children) 
                    q.push(nd);
            }
            ret.push_back(level);
            level.clear();
        }
        return ret;
    }
};