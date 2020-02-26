#define NULL 0
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head, *np;
        while (p)
        {
            np = p->next;
            while (np && np->val == p->val)
            {
                ListNode *temp = np;
                np = np->next;
                delete temp;
            }
            p->next = np;
            p = np;
        }
        return head;
    }
};