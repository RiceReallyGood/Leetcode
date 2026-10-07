#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;

            int target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    ++j;
                    while (j < k && nums[j - 1] == nums[j]) {
                        ++j;
                    }
                } else if (nums[j] + nums[k] > target) {
                    --k;
                    while (j < k && nums[k + 1] == nums[k]) {
                        --k;
                    }
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j - 1] == nums[j]) {
                        ++j;
                    }
                    --k;
                    while (j < k && nums[k + 1] == nums[k]) {
                        --k;
                    }
                }
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return res;
    }
};