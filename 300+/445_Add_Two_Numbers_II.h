#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution { //reverse linked list
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = ReverseList(l1);
        l2 = ReverseList(l2);
        int sum = 0, carry = 0;
        int a, b;
        ListNode* head = nullptr;
        ListNode* p = nullptr;
        while(l1 || l2 || carry){
            a = b = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + carry;
            if(sum >= 10){
                sum %= 10;
                carry = 1;
            }
            else
                carry = 0;
            p = new ListNode(sum);
            p->next = head;
            head = p;
        }
        return head;
    }

private:
    ListNode* ReverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode *p1 = nullptr;
        ListNode *p2 = head;
        ListNode *p3 = nullptr;
        while(p2){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

class Solution { //using stack
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        ListNode* p = l1;
        while(p){
            num1.push(p->val);
            p = p->next;
        }
        p = l2;
        while(p){
            num2.push(p->val);
            p = p->next;
        }
        ListNode* head = nullptr;
        int sum = 0, carry = 0;
        int a , b;
        while(!num1.empty() || !num2.empty() || carry){
            if(!num1.empty()){
                a = num1.top();
                num1.pop();
            }
            else
                a = 0;
            
            if(!num2.empty()){
                b = num2.top();
                num2.pop();
            }
            else
                b = 0;
            
            sum = a + b + carry;
            if(sum > 9){
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            p = new ListNode(sum);
            p->next = head;
            head = p;
        }
        return head;
    }
};