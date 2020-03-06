class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head;
        while(p){
            if(p->child){
                Node *cp = p->child;
                while(cp->next) cp = cp->next;
                cp->next = p->next;
                if(p->next)
                    p->next->prev = cp;
                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;
            }
            p = p->next;
        }
        return head;
    }
};