#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int ret = nums[0] + nums[1] + nums[2];
        int min_diff = abs(ret - target);

        int l = nums.size();
        int i = 0;
        while (i < l && 3 * nums[i] <= target)
            i++;
        if (i == l)
        {
            ret = nums[l - 3] + nums[l - 2] + nums[l - 1];
            return ret;
        }
        else if (i == 0)
        {
            ret = nums[0] + nums[1] + nums[2];
            return ret;
        }

        for (int j = 0; j < i; j++)
        {
            int rest = target - nums[j];
            int k = j + 1, s = l - 1;
            while (k < s)
            {
                int twosum = nums[k] + nums[s];
                if (twosum > rest)
                {
                    if (twosum - rest < min_diff)
                    {
                        min_diff = twosum - rest;
                        ret = twosum + nums[j];
                    }
                    while (k < s - 1 && nums[s - 1] == nums[s])
                        s--;
                    s--;
                }
                else
                {
                    if (rest - twosum < min_diff)
                    {
                        min_diff = rest - twosum;
                        ret = twosum + nums[j];
                    }
                    while (k + 1 < s && nums[k + 1] == nums[k])
                        k++;
                    k++;
                }
            }
            while (j + 1 < i && nums[j + 1] == nums[j])
                j++;
        }
        if (i < l - 2 && nums[i] + nums[i + 1] + nums[i + 2] - target < min_diff)
            ret = nums[i] + nums[i + 1] + nums[i + 2];
        return ret;
    }
};