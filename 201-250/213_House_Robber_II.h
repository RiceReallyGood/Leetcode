#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(OriginRob(nums, 0, nums.size() - 2), OriginRob(nums, 1, nums.size() - 1));
    }
private:
    int OriginRob(vector<int>& nums, int start, int end){
        int rob = 0, unrob = 0;
        for(int i = start; i <= end; i++){
            int temp = rob;
            rob = unrob + nums[i];
            unrob = max(temp, unrob);
        }
        return max(rob, unrob);
    }
};