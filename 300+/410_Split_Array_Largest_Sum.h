#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        vector<vector<int>> dp(m, vector<int>(sz, INT_MAX));
        dp[0][0] = nums[0];
        for(int i = 1; i < sz - m + 1; i++)
            dp[0][i] = dp[0][i - 1] + nums[i];
            
        for(int sp = 1; sp < m; sp++){
            for(int i = sp; i < sz; i++){
                int sum = nums[i];
                for(int j = i - 1; j >= sp - 1; --j){
                    if(sum >= dp[sp][i])
                        break;
                    dp[sp][i] = min(dp[sp][i], max(dp[sp - 1][j], sum));
                    sum += nums[j];
                }
            }
        }
        return dp[m - 1][sz - 1];
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        vector<int> dp(sz, INT_MAX);
        dp[0] = nums[0];
        for(int i = 1; i < sz - m + 1; i++)
            dp[i] = dp[i - 1] + nums[i];
        
        for(int sp = 1; sp < m; sp++){
            for(int i = sz - m + sp; i >= sp; --i){
                int sum = nums[i];
                for(int j = i - 1; j >= sp - 1; --j){
                    if(sum >= dp[i])
                        break;
                    dp[i] = min(dp[i], max(dp[j], sum));
                    sum += nums[j];
                }
            }
        }
        return dp[sz - 1];
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        long lb = nums[0], ub = 0;
        vector<long> partialsum(sz + 1, 0);
        for(int i = 0; i < sz; i++){
            partialsum[i + 1] = partialsum[i] + nums[i];
            if(nums[i] > lb)
                lb = nums[i];
        }
        ub = partialsum.back();
        while(lb < ub){
            int mid = lb + (ub - lb) / 2;
            if(isValid(partialsum, mid, m))
                ub = mid;
            else
                lb = mid + 1;
        }
        return lb;
    }

private:
    bool isValid(vector<long>& partialsum, long target, int intervals){
        long next = target;
        int count = 0;
        auto it = partialsum.begin();
        while(it != partialsum.end()){
            it = upper_bound(it, partialsum.end(), next);
            next = *(it - 1) + target;
            count++;
            if(count > intervals)
                return false;
        }
        return true;
    }
};