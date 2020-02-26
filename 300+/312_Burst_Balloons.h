#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(sz + 2, vector<int>(sz + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int len = 1; len <= sz; len++){
            for(int i = 0; i <= sz - len; i++){
                int j = i + len + 1;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + nums[i] * nums[k] * nums[j] + dp[k][j]);
            }
        }
        return dp[0][sz + 1];
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(sz + 1);
        for(int len = 0; len <= sz; len++)
            dp[len].resize(sz - len + 1);
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int len = 1; len <= sz; len++){
            for(int i = 0; i <= sz - len; i++){
                int j = i + len + 1;
                for(int sublen = 0; sublen < len; sublen++){
                    int k = i + sublen + 1;
                    dp[len][i] = max(dp[len][i], dp[sublen][i] + nums[i] * nums[k] * nums[j] + dp[len - sublen - 1][k]);
                }
            }
        }
        return dp[sz][0];
    }
};