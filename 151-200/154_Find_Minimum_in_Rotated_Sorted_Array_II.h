#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(vector<int>& nums, int l, int r){
        if(l == r)
            return nums[l];
        
        if(nums[l] == nums[r])
            return findMin(nums, l, r - 1);
        
        if(nums[l] < nums[r])
            return nums[l];
        
        int c = l + (r - l) / 2;
        if(nums[c] >= nums[l])
            return findMin(nums, c + 1, r);
        else
            return findMin(nums, l, c);
    }
};