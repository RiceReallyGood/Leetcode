#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};

        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }

        int ret;
        int left_bound, right_bound;

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int center = (left + right) / 2;
            if (nums[center] < target)
                left = center + 1;
            else
                right = center;
        }
        if (nums[left] == target)
            left_bound = left;
        else
            return {-1, -1};

        left = left_bound, right = nums.size() - 1;
        while (left < right)
        {
            int center = (left + right) / 2;
            if (nums[center] <= target)
                left = center + 1;
            else
                right = center;
        }
        if(nums[right]==target)
            right_bound=right;
        else
            right_bound=right-1;

        return {left_bound, right_bound};
    }
};