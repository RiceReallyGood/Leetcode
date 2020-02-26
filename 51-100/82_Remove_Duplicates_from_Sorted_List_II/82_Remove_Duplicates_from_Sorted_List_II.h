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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        head = NULL;
        ListNode *currp = NULL;

        while (!currp && p)
        {
            bool dup = false;
            while (p->next && p->next->val == p->val)
                p = p->next, dup = true;
            if (!dup)
                currp = p;
            p = p->next;
        }
        head = currp;

        while (p)
        {
            bool dup = false;
            while (p->next && p->next->val == p->val)
                p = p->next, dup = true;
            if (!dup)
            {
                currp->next = p;
                currp = p;
            }
            p = p->next;
        }
        if (currp)
            currp->next = NULL;
        return head;
    }
};