#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int64_t> tmp(sz);

        tmp[0] = 1;
        for (int i = 1; i < sz; i++) {
            tmp[i] = tmp[i - 1] * nums[i - 1];
        }

        int64_t prod = 1;
        for (int i = sz - 1; i >= 0; i--) {
            tmp[i] *= prod;
            prod *= nums[i];
        }

        vector<int> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = tmp[i];
        }
        return res;
    }
};