#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ret(sz, 1);
        for(int i = 1; i < sz; i++)
            ret[i] = ret[i - 1] * nums[i - 1];
        int rightprod = 1;
        for(int i = sz - 1; i >= 0; i--){
            ret[i] *= rightprod;
            rightprod *= nums[i];
        }
        return ret;
    }
};