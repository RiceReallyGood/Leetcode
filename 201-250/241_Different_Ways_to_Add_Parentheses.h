#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> opidx = {-1};
        int len = input.length();
        for(int i = 0; i < len; i++)
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
                opidx.push_back(i);
        opidx.push_back(len);
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len));
        for(int i = 1; i < opidx.size(); i++){
            dp[opidx[i - 1] + 1][opidx[i] - 1].push_back(stoi(input.substr(opidx[i - 1] + 1, opidx[i] - opidx[i - 1] - 1)));
            for(int j = i - 2; j >= 0; --j){
                for(int k = j + 1; k < i; k++){
                    for(auto num1 : dp[opidx[j] + 1][opidx[k] - 1])
                        for(auto num2 : dp[opidx[k] + 1][opidx[i] - 1])
                            dp[opidx[j] + 1][opidx[i] - 1].push_back(operate(input[opidx[k]], num1, num2));
                }
            }
        }
        return dp[0][len - 1];
    }

private:
    int operate(char c, int num1, int num2){
        if(c == '+')
            return num1 + num2;
        if(c == '-')
            return num1 - num2;
        return num1 * num2;
    }
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> opidx = {-1};
        int len = input.length();
        for(int i = 0; i < len; i++)
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
                opidx.push_back(i);
        opidx.push_back(len);
        int ops = opidx.size();
        vector<vector<vector<int>>> dp(ops, vector<vector<int>>(ops));
        for(int i = 1; i < ops; i++){
            dp[i - 1][i].push_back(stoi(input.substr(opidx[i - 1] + 1, opidx[i] - opidx[i - 1] - 1)));
            for(int j = i - 2; j >= 0; --j){
                for(int k = j + 1; k < i; k++){
                    for(auto num1 : dp[j][k])
                        for(auto num2 : dp[k][i])
                            dp[j][i].push_back(operate(input[opidx[k]], num1, num2));
                }
            }
        }
        return dp[0][ops - 1];
    }

private:
    int operate(char c, int num1, int num2){
        if(c == '+')
            return num1 + num2;
        if(c == '-')
            return num1 - num2;
        return num1 * num2;
    }
};