#include <climits>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dumnode = new ListNode(INT_MIN);
        ListNode *toinsert = head;
        ListNode *nexttoinsert = nullptr;
        ListNode *p = dumnode;
        while(toinsert){
            nexttoinsert = toinsert->next;
            p = p->val <= toinsert->val ? p : dumnode;
            while(p->next && p->next->val < toinsert->val)
                p = p->next;
            toinsert->next = p->next;
            p->next = toinsert;
            toinsert = nexttoinsert;
        }
        return dumnode->next;
    }
};