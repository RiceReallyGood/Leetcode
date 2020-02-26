#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int maxlen = min(n, 10);
        vector<vector<int>> dp(maxlen + 1, {0, 0});
        dp[1][0] = 1, dp[1][1] = 9;
        for(int i = 2; i <= maxlen; i++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][1]) * (11 - i);
            dp[i][1] = dp[i - 1][1] * (10 - i);
        }
        int sum = 0;
        for(int i = 1; i <= maxlen; i++)
            sum += dp[i][0] + dp[i][1];
        return sum;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        int maxlen = min(n, 10);
        int dp = 9;
        for(int i = 1; i <= n; i++){
            sum += dp;
            dp *= 10 - i;
        }
        return sum;
    }
};