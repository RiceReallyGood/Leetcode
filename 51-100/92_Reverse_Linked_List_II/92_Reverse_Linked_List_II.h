#define NULL nullptr
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
            return head;
        ListNode *p = head;
        ListNode *prevp;
        ListNode *left;

        if (m == 1)
        {
            prevp = head;
            p = head->next;
        }
        else
        {
            for (int i = 0; i < m - 2; i++)
                p = p->next;
            left = p;
            prevp = p->next;
            p = prevp->next;
        }

        for (int i = 0; i < n - m; i++)
        {
            ListNode *nextp = p->next;
            p->next = prevp;
            prevp = p;
            p = nextp;
        }

        if (m == 1)
        {
            head->next = p;
            head = prevp;
        }
        else
        {
            left->next->next = p;
            left->next = prevp;
        }
        return head;
    }
};