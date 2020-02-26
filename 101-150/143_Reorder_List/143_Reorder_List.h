struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode * evenp1 = head, *evenp2;
        ListNode * oddp1 = reverse(slow), *oddp2;
        while(evenp1 != slow){
            evenp2 = evenp1->next;
            evenp1->next = oddp1;
            oddp2 = oddp1->next;
            oddp1->next = evenp2;
            evenp1 = evenp2;
            oddp1 = oddp2;
        }
        slow->next = nullptr;
    }

private:
    ListNode *reverse(ListNode *head){
        if(!head || !head->next)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;
        head->next = nullptr;
        while(p3){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};