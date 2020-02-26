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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //ListNode *new_head, *new_end;
        int nodes = 0;
        ListNode *p = head;
        while (p)
        {
            ++nodes;
            p = p->next;
        }

        if (k > nodes)
            return head;

        ListNode *new_head = head, *new_end = head;
        for (int i = 1; i < k; ++i)
            new_head = new_head->next;

        p = head;
        int circle = 0;
        while (nodes >= k)
        {
            ++circle;
            ListNode *part_end = p, *part_head = p;
            p = p->next;
            ListNode *jump;
            for (int i = 1; i < k; ++i)
            {
                jump = p;
                p = p->next;
                jump->next = part_head;
                part_head = jump;
            }
            nodes -= k;
            if (circle == 1)
                continue;
            new_end->next = part_head;
            new_end = part_end;
        }
        new_end->next = p;
        return new_head;
    }
};