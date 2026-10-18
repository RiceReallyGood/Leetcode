#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            ++len;
            p = p->next;
        }

        ListNode *head2 = head;
        for (int i = 0; i < (len + 1) / 2; i++) {
            head2 = head2->next;
        }

        head2 = reverseList(head2);

        p = head;
        ListNode *p2 = head2;
        while (p2) {
            if (p2->val != p->val) {
                reverseList(head2);
                return false;
            }
            p = p->next;
            p2 = p2->next;
        }
        reverseList(head2);
        return true;
    }

private:
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