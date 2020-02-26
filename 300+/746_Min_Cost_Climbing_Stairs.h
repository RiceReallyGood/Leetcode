#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost);
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        
        if(n == 1)
            return dp[0];
        return min(dp[n - 1], dp[n - 2]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f0 = 0, f1 = 0, f2 = 0;
        for(int i = 0; i < n; i++){
            f2 = min(f0, f1) + cost[i];
            f0 = f1;
            f1 = f2;
        }
        return min(f0, f1);
    }
};