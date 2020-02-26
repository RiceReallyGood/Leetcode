#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 || N >= K - 1 + W) return 1;
        vector<double> dp(K, 0);
        dp[0] = 1;
        double p1 = 0, p2 = 0, rest = 1;
        while(rest > 1e-5){
            vector<double> temp(K, 0);
            for(int t = 1; t <= W; t++){
                double sum = 0;
                int bound1 = max(0, K - t), bound2 = max(0, N - t + 1);
                for(int i = bound2; i < K; i++)
                    sum += dp[i];
                p2 += sum / W;
                sum = 0;
                for(int i = bound1; i < bound2 && i < K; i++)
                    sum += dp[i];
                p1 += sum / W;
                for(int i = 0; i < bound1; i++)
                    temp[i + t] += dp[i];
            }
            for(int i = 0; i < K; i++)
                temp[i] /= W;
            rest = 1 - p1- p2;
            swap(dp, temp);
        }
        return p1;
    }
};

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 || N >= K - 1 + W) return 1;
        vector<double> dp(K + W, 0);
        for(int i = K; i <= N; i++) dp[i] = 1;
        double sum = N - K + 1;
        for(int i = K - 1; i >= 0; i--){
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W];
        }
        return dp[0];
    }
};