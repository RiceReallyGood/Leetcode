#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = k % sz;
        if (k == 0) return;

        int *p = new int[k];
        memcpy(p, &nums[sz - k], k * sizeof(int));
        memmove(&nums[k], &nums[0], (sz - k) * sizeof(int));
        memcpy(&nums[0], p, k * sizeof(int));
        delete[] p;
    }
};