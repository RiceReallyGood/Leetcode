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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = new ListNode(0);
        int res = 0;
        ListNode *l3;
        ListNode *nl3 = ret;
        while (l1 || l2)
        {
            l3 = nl3;
            int ln = l1 ? l1->val : 0;
            int rn = l2 ? l2->val : 0;
            int sum = ln + rn + res;
            l3->val = sum % 10;
            res = sum / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            nl3 = new ListNode(0);
            l3->next = nl3;
        }
        if (res)
        {
            l3 = nl3;
            l3->val = res;
            l3->next = NULL;
        }
        else
        {
            delete nl3;
            l3->next = NULL;
        }
        return ret;
    }
};