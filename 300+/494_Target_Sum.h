#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        unordered_map<int, int> prevsums;
        prevsums[nums[0]] += 1;
        prevsums[-nums[0]] += 1;
        for(int i = 1; i < nums.size(); i++){
            unordered_map<int,int> currsums;
            for(auto it = prevsums.begin(); it != prevsums.end(); it++){
                currsums[(*it).first + nums[i]] += (*it).second;
                currsums[(*it).first - nums[i]] += (*it).second;
            }
            swap(currsums, prevsums);
        }
        return prevsums[S];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum < S || ((S + sum) & 1)) return 0;
        vector<int> sumfreq(2 * sum + 1, 0);
        sumfreq[sum + nums[0]] += 1;
        sumfreq[sum - nums[0]] += 1; 
        for(int i = 1; i < nums.size(); i++){
            vector<int> temp(sumfreq.size(), 0);
            for(int j = 0; j < sumfreq.size(); j++){
                if(sumfreq[j] == 0) continue;
                temp[j + nums[i]] += sumfreq[j];
                temp[j - nums[i]] += sumfreq[j];
            }
            swap(temp, sumfreq);
        }
        return sumfreq[S + sum];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum < S || ((S + sum) & 1)) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(auto& num : nums){
            for(int i = target; i >= num; i--){
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};