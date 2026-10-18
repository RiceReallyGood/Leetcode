#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *p = head->next;
        head->next = NULL;

        while (p) {
            ListNode *tmp = p->next;
            p->next = head;
            head = p;
            p = tmp;
        }

        return head;
    }
};