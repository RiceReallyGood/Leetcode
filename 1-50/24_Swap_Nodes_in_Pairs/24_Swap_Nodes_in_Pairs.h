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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p1, *p2, *p3;
        p1 = head;
        p2 = p1->next;
        head = p2;
        p3 = p2->next;

        while (true)
        {
            p2->next = p1;
            if (p3 == NULL || p3->next == NULL)
            {
                p1->next = p3;
                break;
            }
            else
                p1->next = p3->next;

            p1 = p3;
            p2 = p1->next;
            p3 = p2->next;
        }
        return head;
    }
};