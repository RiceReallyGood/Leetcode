#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num_, int target_) {
        num = num_;
        target = target_;
        vector<string> ops;
        recurse(0, 0, 0, 0, ops);
        return res;
    }

private:
    vector<string> res;
    string num;
    int target;
    void recurse(int index, long prev_operand, long curr_operand, long val,vector<string>& ops){
        if(index == num.size()){
            if(val == target && curr_operand == 0){
                string ans;
                for(int i = 1; i < ops.size(); i++)
                    ans += ops[i];
                res.push_back(ans);
            }
            return;    
        }

        curr_operand = curr_operand * 10 + long(num[index] - '0');
        string curr_operand_str = to_string(curr_operand);

        // NO OP
        if(curr_operand > 0)
            recurse(index + 1, prev_operand, curr_operand, val, ops);

        // ADDITION
        ops.push_back("+");
        ops.push_back(curr_operand_str);
        recurse(index + 1, curr_operand, 0, val + curr_operand, ops);
        ops.pop_back();
        ops.pop_back();

        if(!ops.empty()){
            // SUBTRACTION
            ops.push_back("-");
            ops.push_back(curr_operand_str);
            recurse(index + 1, -curr_operand, 0, val - curr_operand, ops);
            ops.pop_back();
            ops.pop_back();

            // MULTIPLICATION
            ops.push_back("*");
            ops.push_back(curr_operand_str);
            recurse(index + 1, prev_operand * curr_operand, 0, val - prev_operand + prev_operand * curr_operand, ops);
            ops.pop_back();
            ops.pop_back();
        }
    }
};

class Solution {
public:
    vector<string> addOperators(string num_, int target_) {
        if(num_.empty())
            return res;
        num = num_;
        target = target_;
        expr.resize(2 * num.length() - 1);
        recurse(0, -1, 0, 0, 0, 0);
        return res;
    }

private:
    vector<string> res;
    string expr;
    string num;
    int target;
    void recurse(int num_index, int operator_index, int expr_index ,long prev_operand, long curr_operand, long val){
        if(num_index == num.length()){
            if(curr_operand == 0 && val == target)
                res.push_back(expr.substr(0, operator_index));
            return;
        }

        curr_operand = curr_operand * 10 + long(num[num_index] - '0');
        expr[expr_index] = num[num_index];

        // NO OP
        if(curr_operand > 0)
            recurse(num_index + 1, operator_index, expr_index + 1, prev_operand, curr_operand, val);
        

        // ADDITION
        if(operator_index < 0)
            recurse(num_index + 1, expr_index + 1, expr_index + 2, curr_operand, 0, val + curr_operand);
        else{
            // ADDITION
            expr[operator_index] = '+';
            recurse(num_index + 1, expr_index + 1, expr_index + 2, curr_operand, 0, val + curr_operand);
            
            // SUBTRACTION
            expr[operator_index] = '-';
            recurse(num_index + 1, expr_index + 1, expr_index + 2, -curr_operand, 0, val - curr_operand);

            // MULTIPLICATION
            expr[operator_index] = '*';
            recurse(num_index + 1, expr_index + 1, expr_index + 2, prev_operand * curr_operand, 0, val - prev_operand + prev_operand * curr_operand);
        }
    }
};