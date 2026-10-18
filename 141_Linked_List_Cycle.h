#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *fast = head;
        ListNode *slow = head;

        do {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        } while (fast && fast->next);

        return false;
    }
};