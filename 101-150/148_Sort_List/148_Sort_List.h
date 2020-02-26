struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        fast = sortList(fast);
        return merge(head, fast);
    }

private:
    ListNode *merge(ListNode* head1, ListNode* head2){
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        ListNode *dumnode = new ListNode(0);
        ListNode *p = dumnode;
        ListNode * p1 = head1, *p2 = head2;
        while(p1 && p2){
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;    
            }
            p = p->next;
        }
        if(p1)
            p->next = p1;
        else
            p->next = p2;
        return dumnode->next; 
    }
};