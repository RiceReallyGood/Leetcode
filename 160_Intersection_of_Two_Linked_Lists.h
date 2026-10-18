#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0, countB = 0;

        ListNode *pA = headA;
        while (pA) {
            ++countA;
            pA = pA->next;
        }

        ListNode *pB = headB;
        while (pB) {
            ++countB;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;
        if (countA < countB) {
            for (int i = 0; i < countB - countA; i++) {
                pB = pB->next;
            }
        } else {
            for (int i = 0; i < countA - countB; i++) {
                pA = pA->next;
            }
        }

        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};