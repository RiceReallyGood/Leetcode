#define NULL nullptr
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head, *nth_later = head;
        for (int i = 0; i < n; i++)
            p = p->next;
        if (p == NULL)
            return head->next;
        p = p->next;
        while (p != NULL)
        {
            p = p->next;
            nth_later = nth_later->next;
        }
        nth_later->next = nth_later->next->next;
        return head;
    }
};