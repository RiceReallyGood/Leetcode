#include <vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int row, int col) {
        if(N == 0)
            return 0;
        long mod = 1000000007L;
        vector<vector<long>> dp(m, vector<long>(n, 0));
        vector<vector<long>> newdp(m, vector<long>(n, 0));
        //initialize
        for(int j = 0; j < n; j++){
            dp[0][j]++;
            dp[m - 1][j]++;
        }
        for(int i = 0; i < m; i++){
            dp[i][0]++;
            dp[i][n - 1]++;
        }
        long ret = dp[row][col];
        for(int step = 2; step <= N; step++){
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++){
                    newdp[i][j] = 0;
                    dp[i][j] %= mod;
                }
            for(int i = 0; i < m; i++){
                for(int j = 1; j < n - 1; j++)
                    newdp[i][j] += dp[i][j - 1] + dp[i][j + 1];
                if(n > 1){
                    newdp[i][0] += dp[i][1];
                    newdp[i][n - 1] +=  dp[i][n - 2];
                }
            }

            for(int j = 0; j < n; j++){
                for(int i = 1; i < m - 1; i++)
                    newdp[i][j] += dp[i - 1][j] + dp[i + 1][j];
                if(m > 1){
                    newdp[0][j] += dp[1][j];
                    newdp[m - 1][j] +=  dp[m - 2][j];
                }
            }
            ret += newdp[row][col];
            swap(dp, newdp);
        }
        return ret % mod;
    }
};