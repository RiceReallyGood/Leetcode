#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = dp[1] = 0;
        recurse(n, dp);
        return dp[n];
    }

private:
    int recurse(int n, vector<int>& dp){
        if(dp[n] != INT_MAX) return dp[n];

        for(int i = 2; i < dp[n]; i++){
            if(n % i == 0)
                dp[n] = min(dp[n], i + recurse(n / i, dp));
        }
        return dp[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
        int ret = 0, d = 2;
        while(n > 1){
            while(n % d == 0){
                ret += d;
                n /= d;
            }
            d++;
        }
        return ret;
    }
};