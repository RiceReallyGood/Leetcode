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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lesshead = NULL, *lessp = NULL;
        ListNode *largehead = NULL, *largep = NULL;
        ListNode *p = head;
        while (p)
        {
            if (p->val < x)
            {
                if (!lesshead)
                    lesshead = lessp = p;
                else
                {
                    lessp->next = p;
                    lessp = p;
                }
            }
            else
            {
                if (!largehead)
                    largehead = largep = p;
                else
                {
                    largep->next = p;
                    largep = p;
                }
            }
            p = p->next;
        }
        if (largep)
            largep->next = NULL;
        if (!lesshead)
            return largehead;
        else
        {
            lessp->next = largehead;
            return lesshead;
        }
    }
};