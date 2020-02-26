#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp = {0, 0, 1, 2, 4, 6, 9};
        dp.reserve(n + 1);
        for(int i = 7 ; i <= n; i++)
            dp.push_back(max(2 * dp[i - 2], 3 * dp[i - 3]));
        return dp[n];
    }
};