#include <vector>
using namespace std;

class Solution { //TLE
public:
    int kInversePairs(int n, int k) {
        if(k > n * (n - 1) / 2)
            return 0;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1, -1));
        long mod = 1000000007L;
        return recurese(n, k, mod, dp);
    }

private:
    long recurese(int n, int k,const long& mod,vector<vector<long>>& dp){
        if(dp[n][k] != -1)
            return dp[n][k];
        if(k > n * (n - 1) / 2)
            return dp[n][k] = 0;
        if(n == 0)
            return dp[n][k] = 0;
        if(k == 0)
            return dp[n][k] = 1;
        if(k < n)
            dp[n][k] = recurese(n, k - 1, mod, dp) + recurese(n - 1, k, mod, dp);
        else
            dp[n][k] = recurese(n, k - 1, mod, dp) + recurese(n - 1, k, mod, dp) - recurese(n - 1, k - n, mod, dp);

        if(dp[n][k] < 0)
            dp[n][k] += mod;
        else if(dp[n][k] >= mod)
            dp[n][k] -= mod;
        return dp[n][k];
    }
};

class Solution {
public:
    int kInversePairs(int n, int k) {
        if(k > n * (n - 1) / 2)
            return 0;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        long mod = 1000000007L;
        for(int num = 1; num <= n; num++){
            int maxinv = num * (num - 1) / 2;
            dp[num][0] = 1;
            for(int inv = 1; inv < num && inv <= k; inv++)
                dp[num][inv] = (dp[num][inv - 1] + dp[num - 1][inv]) % mod;
            for(int inv = num; inv <= maxinv && inv <= k; inv++)
                dp[num][inv] = (dp[num][inv - 1] + dp[num - 1][inv] - dp[num - 1][inv - num] + mod) % mod;
        }
        return dp[n][k];
    }
};