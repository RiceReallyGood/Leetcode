#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return false;
        return search(nums, target, 0, nums.size() - 1);
    }

private:
    bool search(vector<int> &nums, int target, int left, int right)
    {
        if (right < left)
            return false;
        if (left == right)
            return nums[left] == target;
        int center = (left + right) / 2;
        if (nums[left] < nums[right])
        {
            if (target < nums[left] || target > nums[right])
                return false;
            if (target <= nums[center])
                return search(nums, target, left, center);
            else
                return search(nums, target, center + 1, right);
        }
        else if (nums[left] > nums[right])
        {
            if (nums[center] >= nums[left])
            {
                if (target > nums[center] || target < nums[left])
                    return search(nums, target, center + 1, right);
                else
                    return search(nums, target, left, center);
            }
            else
            {
                if (target <= nums[center] || target >= nums[left])
                    return search(nums, target, left, center);
                else
                    return search(nums, target, center + 1, right);
            }
        }
        else
            return nums[left] == target || search(nums, target, left + 1, right - 1);
    }
};