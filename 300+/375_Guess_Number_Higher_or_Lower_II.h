#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        //len == 1
        for(int i = 1; i <= n; i++)
            dp[i][i] = 0;
        
        //len == 2
        for(int i = 1; i <= n - 1; i++)
            dp[i][i + 1] = i;
        
        for(int len = 3; len <= n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
        return dp[1][n];
    }
};