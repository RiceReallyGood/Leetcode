#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) {
            int j = i + 1;
            while (j < nums.size() && nums[j] > nums[i]) {
                ++j;
            }
            --j;
            swap(nums[i], nums[j]);
        }

        i = i + 1;
        int j = nums.size() - 1;

        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};