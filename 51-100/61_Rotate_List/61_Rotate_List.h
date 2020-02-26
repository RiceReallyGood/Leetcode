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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k == 0)
            return head;
        ListNode *p1 = head, *p2 = head;
        ListNode *last;
        int diff = 0;
        while (diff < k && p1 != NULL)
        {
            p1 = p1->next;
            diff++;
        }
        if (p1 == NULL)
        {
            k %= diff;
            if (k == 0)
                return head;
            p1 = head;
            for (int i = 0; i < k; i++)
                p1 = p1->next;
            while (p1->next != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = head;
            head = p2->next;
            p2->next = NULL;
        }
        else
        {
            while (p1->next != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = head;
            head = p2->next;
            p2->next = NULL;
        }
        return head;
    }
};