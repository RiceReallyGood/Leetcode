#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;
        sum_count[0] = 1;
        int ret = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            if(sum_count.find(target) != sum_count.end())
                ret += sum_count[target];
            sum_count[sum]++;
        }
        return ret;
    }
};