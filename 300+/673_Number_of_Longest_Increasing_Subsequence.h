#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp1[j] + 1 > dp1[i]){
                        dp1[i] = dp1[j] + 1;
                        dp2[i] = dp2[j];
                    }
                    else if(dp1[j] + 1 == dp1[i])
                        dp2[i] += dp2[j];
                }
            }
            maxlen = max(maxlen, dp1[i]);
        }

        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
            if(dp1[i] == maxlen) ret += dp2[i];
        return ret;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp;
        vector<int> lens(nums.size(), 1), counts(nums.size(), 0);
        int maxlen = 0, ret = 0;

        for(int i = 0; i < nums.size(); i++){
            int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(index == dp.size()) dp.push_back(nums[i]);
            else dp[index] = nums[i];

            lens[i] = index + 1;
            if(lens[i] == 1) counts[i] = 1;
            else{
                for(int j = 0; j < i; j++){
                    if(nums[j] < nums[i] && lens[j] + 1 == lens[i]) counts[i] += counts[j];
                }
            }

            if(lens[i] > maxlen){
                maxlen = lens[i];
                ret = counts[i];
            }
            else if(lens[i] == maxlen)
                ret += counts[i];
        }
        return ret;
    }
};