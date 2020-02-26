#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = INT_MAX;
        for(auto &num : nums)
            if(num < minnum)
                minnum = num;
        int ret = 0;
        for(auto &num : nums)
            ret += num - minnum;
        return ret;
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = nums[0];
        long sum = 0;
        for(auto num : nums){
            sum += num;
            minnum = min(minnum, num);
        }
        return sum - nums.size() * minnum;
    }
};