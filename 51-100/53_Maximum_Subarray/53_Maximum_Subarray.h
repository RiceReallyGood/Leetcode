#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)
                nums[i]+=nums[i-1];
            if(nums[i]>maxsum)
                maxsum=nums[i];
        }
        return maxsum;
    }
};