#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);

        ListNode *tail = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                tail = list1;

                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = list2;

                list2 = list2->next;
            }
        }

        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};