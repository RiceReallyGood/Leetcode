#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n - 1; i++)
            dp[i][i + 1] = 0;
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                int prod = A[i] * A[j];
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], prod * A[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};