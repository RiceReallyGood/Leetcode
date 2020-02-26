#include <vector>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ret = 2;
        vector<int> lastindex(10001, -1);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int target = 2 * A[i] - A[j];
                if(target < 0 || target > 10000 || lastindex[target] == -1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[lastindex[target]][i] + 1;
                ret = max(ret, dp[i][j]);
            }
            lastindex[A[i]] = i;
        }
        return ret;
    }
};