#include <vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(K, vector<double>(n, 0));
        for(int l = 0; l < K; l++)
            dp[l][0] = A[0];
        for(int i = 1; i < n; i++){
            double sum = A[i];
            for(int j = i - 1; j >= 0; j--){
                double avrg = sum / (i - j);
                for(int l = 1; l < K; l++)
                    dp[l][i] = max(dp[l][i], dp[l - 1][j] + avrg);
                sum += A[j];
            }
            dp[0][i] = sum / (i + 1);
        }
        return dp[K - 1][n - 1];
    }
};