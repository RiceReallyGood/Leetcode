//use heap

#include <vector>
using namespace std;

#define NULL nullptr
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct LNptr
{
    LNptr() : p(NULL) {}
    LNptr(ListNode *ptr) : p(ptr) {}
    ListNode *p;
    friend bool operator<(LNptr p1, LNptr p2)
    {
        return p1.p->val < p2.p->val;
    }

    friend bool operator>(LNptr p1, LNptr p2)
    {
        return p1.p->val > p2.p->val;
    }

    friend bool operator==(LNptr p1, LNptr p2)
    {
        return p1.p->val == p2.p->val;
    }
};

class Solution
{
  public:
    typedef vector<LNptr>::iterator It;
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<LNptr> first_member;
        for (auto p : lists)
        {
            if (p != NULL)
                first_member.push_back(p);
        }

        if (first_member.empty())
            return NULL;

        //build heap
        for (int i = (first_member.size() - 2) / 2; i >= 0; --i)
        {
            It it = first_member.begin() + i;
            It minchild;
            while ((minchild = MinChild(first_member.begin(), it, first_member.size())) != first_member.end())
            {
                if (*minchild < *it)
                {
                    Swap(minchild, it);
                    it = minchild;
                }
                else
                    break;
            }
        }

        ListNode *ret = first_member[0].p;
        ListNode *last = first_member[0].p;
        //delete the min one and insert the next one;
        while (!first_member.empty())
        {
            if (first_member[0].p->next != NULL)
            {
                LNptr temp = first_member[0].p->next;
                It it = first_member.begin();
                It minchild;
                while ((minchild = MinChild(first_member.begin(), it, first_member.size())) != first_member.end())
                {
                    if (*minchild < temp)
                    {
                        *it = *minchild;
                        it = minchild;
                    }
                    else
                        break;
                }
                *it = temp;
                last->next = first_member[0].p;
                last = last->next;
            }
            else
            {
                LNptr temp = first_member.back();
                first_member.pop_back();
                if (first_member.empty())
                    break;
                It it = first_member.begin();
                It minchild;
                while ((minchild = MinChild(first_member.begin(), it, first_member.size())) != first_member.end())
                {
                    if (*minchild < temp)
                    {
                        *it = *minchild;
                        it = minchild;
                    }
                    else
                        break;
                }
                *it = temp;
                last->next = first_member[0].p;
                last = last->next;
            }
        }
        return ret;
    }

    void Swap(It a, It b)
    {
        auto temp = *a;
        *a = *b;
        *b = temp;
    }

    It MinChild(It beg, It iter, size_t sz)
    {
        auto index = iter - beg;
        if (index * 2 + 2 > sz)
            return beg + sz;
        else if (index * 2 + 2 == sz)
            return beg + 2 * index + 1;
        else
        {
            auto LeftChild = beg + 2 * index + 1;
            auto RightChild = LeftChild + 1;
            return *LeftChild < *RightChild ? LeftChild : RightChild;
        }
    }
};