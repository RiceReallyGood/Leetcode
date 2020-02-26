#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) { //确定每一个数放在哪个集合里
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum == 0 || sum % 4 != 0)
            return false;
        int partialsum = sum / 4;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > partialsum) return false;
        vector<int> targets(4, 0);
        return recurse(nums, 0, targets, partialsum);
    }

private:
    bool recurse(vector<int>& nums, int index, vector<int>& buckets, int target){
        if(index == nums.size()) return true;
        if(nums[index] == 0) return recurse(nums, index + 1, buckets, target);

        for(int i = 0; i < buckets.size(); i++){
            if(buckets[i]  + nums[index] <= target){
                buckets[i] += nums[index];
                if(recurse(nums, index + 1, buckets, target)) return true;
                buckets[i] -= nums[index];
            }
            if(buckets[i] == 0) break;
        }
        return false;
    }
};

class Solution { //确定每一个集合有哪些数
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum == 0 || sum % 4 != 0)
            return false;
        partialsum = sum / 4;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > partialsum) return false;
        vector<bool> used(nums.size(), false);
        return recurse(nums, 0, used, 4, partialsum);
    }

private:
    int partialsum;
    bool recurse(vector<int>& nums, int index, vector<bool>& used, int tofill, int target){
        if(tofill == 1) return true;
        if(target == 0) return recurse(nums, 0, used, tofill - 1, partialsum);

        for(int i = index; i < nums.size(); i++){
            if(used[i] || nums[i] > target) continue;
            used[i] = true;
            if(recurse(nums, i + 1, used, tofill, target - nums[i]))
                return true;
            used[i] = false;
            if(target == partialsum)
                break;
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        return false;
    }
};

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum == 0 || sum % 4 != 0)
            return false;
        int partialsum = sum / 4;
        sort(nums.begin(), nums.end());
        if(*(nums.rbegin()) > partialsum) return false;
        int totalstates = 1 << nums.size();
        vector<bool> dp(totalstates, false);
        vector<int> total(totalstates, 0);
        dp[0] = true;

        for(int state = 0; state < totalstates; state++){
            if(!dp[state]) continue;
            for(int i = 0; i < nums.size(); i++){
                int future = state | (1 << i);
                if(future == state || dp[future]) continue;
                if(total[state] % partialsum + nums[i] <= partialsum){
                    dp[future] = true;
                    total[future] = total[state] + nums[i];
                }
                else
                    break;
            }
        }
        return dp[totalstates - 1];
    }
};


//这个是0ms的那个代码但是这个算法是错误的
//比如对于测试用例 {10, 10, 10, 10, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6}
//这显然是可以组成正方形的但是下面的算法找不到解
//所以这个算法是错误的虽然他很快但是不能这么做(即使它通过了网站上的所有测试用例但是它是错误的)
class Solution {
public:
  bool makesquare(vector<int>& nums) {
    if (nums.empty() || nums.size() < 4) return false;
    int sum = 0;
    for (auto num : nums)
      sum += num;
    if (sum % 4 != 0) return false;

    sort(nums.rbegin(), nums.rend());

    vector<int> used(nums.size(), 0);

    if (!dfs(nums, 0, sum/4, used)) return false;
    if (!dfs(nums, 0, sum/4, used)) return false;
    if (!dfs(nums, 0, sum/4, used)) return false;
    return true;
  }

  bool dfs(vector<int>& nums, int i, int target, vector<int> &used) {
    if (i >= nums.size()) return false;
    if (used[i]) return dfs(nums, i+1, target, used);
    if (target == nums[i]) {
      used[i] = 1;
      return true;
    }
    else if (target > nums[i]) {
      used[i] = 1;
      if (dfs(nums, i+1, target - nums[i], used)) return true;
      used[i] = 0;
    }
    return dfs(nums, i+1, target, used);
  }



};