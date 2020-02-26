#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {  //有括号
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        unordered_map<char, int> prio = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i]))
                    num = num * 10 + int(s[i++] - '0');
                --i;
                nums.push(num);
            }
            else if(s[i] == '(')
                ops.push('(');
            else if(s[i] == ')'){
                if(ops.top() != '(')
                    operate(ops, nums);
                ops.pop();
            }
            else{
                if(!ops.empty() && ops.top() != '(' && prio[s[i]] <= prio[ops.top()])
                    operate(ops, nums);
                ops.push(s[i]);
            }
        }
        while(!ops.empty())
            operate(ops, nums);
        return nums.top();
    }

private:
    void operate(stack<char> & ops, stack<int>& nums){
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if(op == '+')
            nums.push(num1 + num2);
        else if(op == '-')
            nums.push(num1 - num2);
        else if(op == '*')
            nums.push(num1 * num2);
        else
            nums.push(num1 / num2);
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i]))
                    num = num * 10 + int(s[i++] - '0');
                --i;
                nums.push(num);
            }
            else{
                if(s[i] == '+' || s[i] == '-'){
                    while(!ops.empty())
                        operate(ops, nums);
                    ops.push(s[i]);
                }
                else{
                    if(!ops.empty() && (ops.top() ==  '*' || ops.top() == '/'))
                        operate(ops, nums);
                    ops.push(s[i]);
                }
            }
        }
        while(!ops.empty())
            operate(ops, nums);
        return nums.top();
    }

private:
    void operate(stack<char> & ops, stack<int>& nums){
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if(op == '+')
            nums.push(num1 + num2);
        else if(op == '-')
            nums.push(num1 - num2);
        else if(op == '*')
            nums.push(num1 * num2);
        else
            nums.push(num1 / num2);
    }
};

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if(len == 0) return 0;
        stack<int> stack;
        int num = 0;
        char sign = '+';
        for(int i=0; i<len; i++){
            if(isdigit(s[i])) num = num*10+ (s[i]-'0');
            if((!isdigit(s[i]) && ' ' != s[i]) || i==len-1){
                if(sign=='-') stack.push(-num);
                if(sign=='+') stack.push(num);
                if(sign=='*'){
                    int val = stack.top();
                    stack.pop();
                    stack.push(val*num);
                }
                if(sign=='/'){
                    int val = stack.top();
                    stack.pop();
                    stack.push(val/num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!stack.empty()){
            int val = stack.top();
            stack.pop();
            res += val;
        }
        return res;
    }
};

class Solution {
public:
    int calculate(string s) {
        int pos = 0, cur_res = 0, res = 0;
        char sign = '+';
        while (pos < s.size()) {
            char cur = s[pos]; 
            if (isdigit(cur)) {
                cur_res = cur_res * 10 + (cur - '0');
            }
            if (cur == '+' || cur == '-') {
                res += sign == '+' ? cur_res : -cur_res;
                sign = cur;
                cur_res = 0;
            }
            if (cur == '*' || cur == '/') {
                char sign2 = cur;
                pos++; // skip cur
                int next = 0; // cur_res = cur_res * or / next
                while (s[pos] == ' ') {
                    pos++;
                }
                while (isdigit(s[pos])) {
                    next = next * 10 + (s[pos++] - '0');
                }
                cur_res = sign2 == '*' ? cur_res * next : cur_res / next;
                continue; // skip pos++
            }
            pos++;
        }
        if (cur_res != 0) {
            res += sign == '+' ? cur_res : -cur_res;
        }
        return res;
    }
};