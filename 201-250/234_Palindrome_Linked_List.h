struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* p1 = head;
        while(p1){
            ++len;
            p1 = p1->next;
        }
        if(len < 2)
            return true;
        int halflen = len / 2;
        ListNode* righthead = head;
        for(int i = 0; i < halflen; i++)
            righthead = righthead->next;
        
        //reverse linkedlist
        p1 = nullptr;
        ListNode *p2 = head, *p3;
        while(p2 != righthead){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }

        if(len & 1)
            p2 = righthead->next;
        else
            p2 = righthead;
        p3 = p1;
        
        while(p2){
            if(p2->val != p3->val)
                return false;
            p2 = p2->next;
            p3 = p3->next;
        }
        return true;
    }
};