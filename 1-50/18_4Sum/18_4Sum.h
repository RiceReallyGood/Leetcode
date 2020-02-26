#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int i1bound = 0;
        int l = nums.size();

        while (i1bound < l && 4 * nums[i1bound] <= target)
            i1bound++;

        for (int i1 = 0; i1 < i1bound; i1++)
        {
            int target3 = target - nums[i1];
            int i2bound = i1 + 1;
            while (i2bound < l && 3 * nums[i2bound] <= target3)
                i2bound++;
            for (int i2 = i1 + 1; i2 < i2bound; i2++)
            {
                int target2 = target3 - nums[i2];
                int i3 = i2 + 1, i4 = l - 1;
                while (i3 < i4)
                {
                    if (nums[i3] + nums[i4] < target2)
                    {
                        while (i3 + 1 < i4 && nums[i3 + 1] == nums[i3])
                            i3++;
                        i3++;
                    }
                    else if (nums[i3] + nums[i4] > target2)
                    {
                        while (i4 - 1 > i3 && nums[i4 - 1] == nums[i4])
                            i4--;
                        i4--;
                    }
                    else
                    {
                        ret.push_back({nums[i1], nums[i2], nums[i3], nums[i4]});
                        while (i3 + 1 < i4 && nums[i3 + 1] == nums[i3])
                            i3++;
                        i3++;
                        while (i4 - 1 > i3 && nums[i4 - 1] == nums[i4])
                            i4--;
                        i4--;
                    }
                }
                while (i2 + 1 < i2bound && nums[i2 + 1] == nums[i2])
                    i2++;
            }
            while (i1 + 1 < i1bound && nums[i1 + 1] == nums[i1])
                i1++;
        }
        return ret;
    }
};