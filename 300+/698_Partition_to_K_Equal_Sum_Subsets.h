#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution { //确定每一个数放在哪个集合里
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum = 0;
        for(auto& num : nums)
            totalsum += num;
        if(totalsum % k != 0)
            return false;
        int partialsum = totalsum / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > partialsum) return false;
        vector<int> targets(k, partialsum);
        return recurse(nums, 0, targets);
    }

private:
    bool recurse(vector<int>& nums,int index, vector<int>& targets){
        if(index == nums.size())
            return true;
        if(nums[index] == 0)
            return recurse(nums, index + 1, targets);
        for(int i = 0; i < targets.size(); i++){
            if(nums[index] <= targets[i]){
                targets[i] -= nums[index];
                if(recurse(nums, index + 1, targets))
                    return true;
                targets[i] += nums[index];
            }
        }
        return false;
    }
};

class Solution { //确定每一个集合有哪些数
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum = 0;
        for(auto& num : nums)
            totalsum += num;
        if(totalsum % k != 0)
            return false;
        partialsum = totalsum / k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > partialsum) return false;
        vector<bool> used(nums.size(), false);
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0) used[i] = true;
        return recurse(nums, 0,used, k, partialsum);
    }

private:
    int partialsum;
    bool recurse(vector<int>& nums, int index, vector<bool>& used, int k, int target){
        if(k == 1)
            return true;
        if(target == 0)
            return recurse(nums, 0, used, k - 1, partialsum);
        
        for(int i = index; i < nums.size(); i++){
            if(!used[i] && nums[i] <= target){
                used[i] = true;
                target -= nums[i];
                if(recurse(nums, i + 1,used, k, target))
                    return true;
                used[i] = false;
                target += nums[i];
            }
        }
        return false;
    }
};