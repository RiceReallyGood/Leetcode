#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        int l = 0, r = N / 2;
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[2 * c + 1] == nums[2 * c])
                l = c + 1;
            else
                r = c;
        }
        return nums[2 * l];
    }
};