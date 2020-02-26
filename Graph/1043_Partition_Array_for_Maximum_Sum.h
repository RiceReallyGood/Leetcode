#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N, 0);
        int maxval = 0;
        for(int i = 0; i < K; i++){
            maxval = max(maxval, A[i]);
            dp[i] = (i + 1) * maxval;
        }


        for(int i = K; i < N; i++){
            maxval = 0;
            for(int len = 1; len <= K; len++){
                maxval = max(maxval, A[i - len + 1]);
                dp[i] = max(dp[i], dp[i - len] + len * maxval);
            }
        }
        return dp.back();
    }
};