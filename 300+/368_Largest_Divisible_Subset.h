#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())
            return vector<int>();
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int maxindex = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> ret;
        ret.push_back(nums[maxindex]);
        int previndex = maxindex;
        for(int i = maxindex - 1; i >= 0; i--){
            if(nums[previndex] % nums[i] == 0 && dp[i] + 1 == dp[previndex]){
                ret.push_back(nums[i]);
                previndex = i;
            }
        }
        return ret;
    }
};