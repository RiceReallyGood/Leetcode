#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numstack;
        int num1, num2;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                num2 = numstack.top();
                numstack.pop();
                num1 = numstack.top();
                numstack.pop();
                numstack.push(num1 + num2);
            }
            else if(tokens[i] == "-"){
                num2 = numstack.top();
                numstack.pop();
                num1 = numstack.top();
                numstack.pop();
                numstack.push(num1 - num2);
            }
            else if(tokens[i] == "*"){
                num2 = numstack.top();
                numstack.pop();
                num1 = numstack.top();
                numstack.pop();
                numstack.push(num1 * num2);
            }
            else if(tokens[i] == "/"){
                num2 = numstack.top();
                numstack.pop();
                num1 = numstack.top();
                numstack.pop();
                numstack.push(num1 / num2);
            }
            else
                numstack.push(stoi(tokens[i]));
        }
        return numstack.top();
    }
};