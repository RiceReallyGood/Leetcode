#include <vector>
using namespace std;

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int center = (left + right) / 2;
            if (nums[center] < target)
                left = center + 1;
            else
                right = center;
        }
        if (nums[left] < target)
            return left + 1;
        else
            return left;
    }
};