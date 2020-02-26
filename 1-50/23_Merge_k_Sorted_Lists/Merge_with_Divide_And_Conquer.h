#include <vector>
using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int Left = lists.size();
        if (Left == 0)
            return NULL;
        while (Left > 1)
        {
            int MergeTo = (Left + 1) / 2;
            for (int i = 0; i < Left / 2; ++i)
            {
                int partner = i + MergeTo;
                ListNode *p1 = lists[i], *p2 = lists[partner];
                ListNode *last = NULL;
                if (p1 == NULL)
                {
                    if (p2 == NULL)
                        continue;
                    else
                    {
                        last = p2;
                        p2 = p2->next;
                    }
                }
                else
                {
                    if (p2 == NULL)
                    {
                        last = p1;
                        p1 = p1->next;
                    }
                    else
                    {
                        if (p1->val < p2->val)
                        {
                            last = p1;
                            p1 = p1->next;
                        }
                        else
                        {
                            last = p2;
                            p2 = p2->next;
                        }
                    }
                }
                lists[i] = last;
                while (p1 && p2)
                {
                    if (p1->val < p2->val)
                    {
                        last->next = p1;
                        p1 = p1->next;
                    }
                    else
                    {
                        last->next = p2;
                        p2 = p2->next;
                    }
                    last = last->next;
                }
                if (last)
                    last->next = (p1 != NULL) ? p1 : p2;
            }
            Left = MergeTo;
        }
        return lists[0];
    }
};