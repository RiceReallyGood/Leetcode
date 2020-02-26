struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumhead = new ListNode(0);
        dumhead->next = head;
        ListNode *p = dumhead;
        while(p->next){
            if(p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dumhead->next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **indicator = &head;
        while(*indicator){
            if((*indicator)->val == val)
                *indicator = (*indicator)->next;
            else
                indicator = &((*indicator)->next);
        }
    }
};