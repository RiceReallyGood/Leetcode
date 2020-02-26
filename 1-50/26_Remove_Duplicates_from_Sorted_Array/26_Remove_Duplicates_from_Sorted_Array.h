#include <vector>
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int i = 1, j = 1;
        while (j < nums.size())
        {
            if (nums[j] == nums[j - 1])
                j++;
            else
            {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};