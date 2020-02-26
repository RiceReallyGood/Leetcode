#include <string>
#include <stack>
using namespace std;

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
                while(i < len && isdigit(s[i]))
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
                if(!ops.empty() && ops.top() != '(')
                    operate(ops, nums);
                ops.push(s[i]);    
            }
        }
        if(!ops.empty())
            operate(ops, nums);
        return nums.top();
    }

private:
    void operate(stack<char> & ops, stack<int>& nums){
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        if(ops.top() == '+')
            nums.push(num1 + num2);
        else
            nums.push(num1 - num2);
        ops.pop();
    }
};


class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int len = s.length();
        int num = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ' ')
                continue;
            
            if(isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            else{
                if(s[i] == ')'){
                    if(ops.top() != '(')
                        num = operate(ops, nums, num);
                    ops.pop();
                }
                else if(s[i] == '(')
                    ops.push('(');
                else{
                    if(!ops.empty() && ops.top() != '(')
                        num = operate(ops, nums, num);
                    nums.push(num);
                    num = 0;
                    ops.push(s[i]);
                }
            }
        }
        if(!ops.empty())
            return operate(ops, nums, num);
        return num;
    }

private:
    int operate(stack<char>& ops, stack<int>& nums, int num){
        char op = ops.top();
        ops.pop();
        int val = nums.top();
        nums.pop();
        if(op == '+')
            return val + num;
        else
            return val - num;
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<int> results;
        stack<char> signs;
        int len = s.length();
        char sign = '+';
        int res = 0, num = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ' ')
                continue;
            
            if(isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            else if(s[i] == '+' || s[i] == '-'){
                res += sign == '+' ? num : -num;
                num = 0;
                sign = s[i];
            }
            else if(s[i] == '('){
                results.push(res);
                signs.push(sign);
                res = 0;
                sign = '+';
            }
            else{ //s[i] == ')'
                res += sign == '+' ? num : -num;
                sign = signs.top();
                signs.pop();
                res = sign == '+' ? results.top() + res : results.top() - res;
                results.pop();
                num = 0;
            }
        }
        res += sign == '+' ? num : -num;
        return res;
    }
};