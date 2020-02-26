#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = legth(headA);
        int lenB = legth(headB);
        int diff = lenA - lenB;
        if(lenB > lenA){
            swap(headA, headB);
            diff = -diff;
        }
        ListNode *p1 = headA, *p2 = headB;
        for(int i = 0; i < diff; i++)
            p1 = p1->next;
        
        while(p1){
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }

private:
    int legth(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
};