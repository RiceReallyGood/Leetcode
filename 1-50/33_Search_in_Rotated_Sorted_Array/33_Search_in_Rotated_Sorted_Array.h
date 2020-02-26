#include <vector>
using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        if (nums[0] < nums.back())
            return BinarySearch(nums, 0, nums.size() - 1, target);

        int max_index = FindIndexofMaximun(nums, 0, nums.size() - 1);
        int max = nums[max_index];

        if (target >= nums[0] && target <= max)
            return BinarySearch(nums, 0, max_index, target);
        else
            return BinarySearch(nums, max_index + 1, nums.size() - 1, target);
    }

    int FindIndexofMaximun(vector<int> &nums, int left, int right)
    {
        int center = (left + right) / 2;
        if (nums[center] > nums[center + 1])
            return center;
        if (nums[left] < nums[center])
            return FindIndexofMaximun(nums, center + 1, right);
        else
            return FindIndexofMaximun(nums, left, center);
    }

    int BinarySearch(vector<int> &nums, int left, int right, int target)
    {
        if (left == right)
        {
            if(nums[left]==target)
                return left;
            else
                return -1;
        }
        int center = (left + right) / 2;
        if (nums[center] == target)
            return center;
        if (nums[center] < target)
            return BinarySearch(nums, center + 1, right, target);
        else
            return BinarySearch(nums, left, center, target);
    }
};