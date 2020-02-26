#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = nums[0];
        int currmin = nums[0];
        int maxp = nums[0];
        int sz = nums.size();
        for(int i = 1; i < sz; i++){
            if(nums[i] > 0){
                currmax = currmax > 0 ? currmax * nums[i] : nums[i];
                currmin = currmin < 0 ? currmin * nums[i] : nums[i];
                maxp = max(maxp, currmax);
            }
            else{
                int temp = currmin;
                currmin = currmax > 0 ? currmax * nums[i] : nums[i];
                currmax = temp < 0 ? temp * nums[i] : 0;
                maxp = max(maxp, currmax);
            }
        }
        return maxp;
    }
};