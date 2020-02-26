#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0){
            for(int i = 1; i < n; i++)
                if(nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            return false;
        }
        k = k < 0 ? -k : k;
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++){
            sum[i + 1] = sum[i] + nums[i];
            for(int j = i - 1; j >= 0; j--){
                if((sum[i + 1] - sum[j]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return false;
        if(k == 0){
            for(int i = 1; i < n; i++)
                if(nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            return false;
        }
        k = k < 0 ? -k : k;
        unordered_map<int, int> sum_index;
        int sum = 0;
        sum_index[0] = -1;
        for(int i = 0; i < n; i++){
            sum = (sum + nums[i]) % k;
            if(sum_index.find(sum) != sum_index.end()){
                if(sum_index[sum] < i - 1)
                    return true;
            }
            else
                sum_index[sum] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return false;
        if(k == 0){
            for(int i = 1; i < n; i++)
                if(nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            return false;
        }
        k = k < 0 ? -k : k;
        unordered_set<int> sums;
        int prevsum = 0, sum = 0; 
        for(int i = 0; i < n; i++){
            sum = (prevsum + nums[i]) % k;
            if(sums.find(sum) != sums.end())
                return true;
            sums.insert(prevsum);
            prevsum = sum;
        }
        return false;
    }
};