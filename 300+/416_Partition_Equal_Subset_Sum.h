#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto& num : nums)
            totalsum += num;
        if(totalsum & 1)
            return false;
        int halfsum = totalsum / 2;
        vector<bool> dp(halfsum + 1, false);
        dp[0] = true;
        for(auto& num : nums){
            if(num > halfsum) return false;
            if(dp[halfsum - num]) return true;
            for(int i = halfsum - num - 1; i >= 0; --i)
                if(dp[i]) dp[i + num] = true;
        }
        return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto& num : nums)
            totalsum += num;
        if(totalsum & 1)
            return false;
        int halfsum = totalsum / 2;
        sort(nums.begin(), nums.end(), std::greater<int>());
        vector<bool> dp(halfsum + 1, false);
        dp[0] = true;
        int maxsum = 0;
        for(auto& num : nums){
            if(num > halfsum) return false;
            if(dp[halfsum - num]) return true;
            for(int i = min(maxsum, halfsum - num - 1); i >= 0; --i){
                if(dp[i]){
                    dp[i + num] = true;
                    maxsum = max(maxsum, i + num);
                } 
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto& num : nums)
            totalsum += num;
        if(totalsum & 1)
            return false;
        int halfsum = totalsum / 2;
        sort(nums.rbegin(), nums.rend());
        return recurse(nums, 0, halfsum);
    }

private:
    bool recurse(vector<int>& nums, int index, int target){
        if(index == nums.size() || nums[index] > target)
            return false;
        if(nums[index] == target)
            return  true;
        
        return recurse(nums, index + 1, target - nums[index]) || recurse(nums, index + 1, target);
    }
};