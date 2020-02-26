#include <vector>
using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int lastindex = nums.size() - 1;
        int i = lastindex - 1;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i < 0)
        {
            reverse(nums, 0, lastindex);
            return;
        }

        reverse(nums, i + 1, lastindex);

        int j = lastindex;
        while (nums[j] > nums[i])
            j--;
        int temp = nums[j + 1];
        nums[j + 1] = nums[i];
        nums[i] = temp;
        return;
    }
    void reverse(vector<int> &nums, int left, int right)
    {
        int temp;
        for (int i = left, j = right; i < j; i++, j--)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};