#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*,Node*> nodemap;
        Node *newhead = new Node(head->val, nullptr, head->random);
        nodemap[head] = newhead;
        Node *node = newhead;
        while(head->next){
            node->next = new Node(head->next->val, nullptr, head->next->random);
            head = head->next;
            node = node->next;
            nodemap[head] = node;
        }
        node = newhead;
        while(node){
            node->random = nodemap[node->random];
            node= node->next;
        }
        return newhead;
    }
};