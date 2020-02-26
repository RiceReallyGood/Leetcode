#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//广度优先 队列实现
class Solution {
public:
    Node* cloneGraph(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*,Node*> nodemap;
        queue<Node*> q;
        q.push(head);
        Node *newhead = new Node(head->val, head->neighbors);
        nodemap[head] = newhead;
        Node *node, *newnode;
        while(!q.empty()){
            node = q.front();
            q.pop();
            newnode = nodemap[node];
            for(int i = 0; i < newnode->neighbors.size(); i++){
                if(nodemap.find(newnode->neighbors[i]) == nodemap.end()){
                    q.push(newnode->neighbors[i]);
                    nodemap[newnode->neighbors[i]] = new Node(newnode->neighbors[i]->val,newnode->neighbors[i]->neighbors);
                }
                newnode->neighbors[i] = nodemap[newnode->neighbors[i]];
            }
        }
        return newhead;
    }
};

//广度优先 链表实现
class Solution {
public:
    Node* cloneGraph(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*,Node*> nodemap;
        list<Node*> q;
        q.push_back(head);
        Node *newhead = new Node(head->val, head->neighbors);
        nodemap[head] = newhead;
        Node *node, *newnode;
        while(!q.empty()){
            node = q.front();
            q.pop_front();
            newnode = nodemap[node];
            for(int i = 0; i < newnode->neighbors.size(); i++){
                if(nodemap.find(newnode->neighbors[i]) == nodemap.end()){
                    q.push_back(newnode->neighbors[i]);
                    nodemap[newnode->neighbors[i]] = new Node(newnode->neighbors[i]->val,newnode->neighbors[i]->neighbors);
                }
                newnode->neighbors[i] = nodemap[newnode->neighbors[i]];
            }
        }
        return newhead;
    }
};

//深度优先 递归实现
class Solution {
public:
    Node* cloneGraph(Node* head) {
        if(!head)
            return nullptr;
        if(nodemap.find(head) != nodemap.end())
            return head;
        
        Node *newhead = new Node(head->val, head->neighbors);
        nodemap[head] = newhead;
        for(int i = 0; i < newhead->neighbors.size(); i++){
            if(nodemap.find(newhead->neighbors[i]) != nodemap.end())
                newhead->neighbors[i] = nodemap[newhead->neighbors[i]];
            else
                newhead->neighbors[i] = cloneGraph(newhead->neighbors[i]);
        }
        return newhead;
    }
private:
    unordered_map<Node*,Node*> nodemap;
};