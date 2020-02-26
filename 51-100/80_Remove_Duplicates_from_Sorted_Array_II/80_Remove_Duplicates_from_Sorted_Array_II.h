#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (j + 1 < nums.size() && nums[j] == nums[j + 1])
            {
                nums[i] = nums[i + 1] = nums[j];
                i += 2;
                j++;
                while (j < nums.size() && nums[j - 1] == nums[j])
                    j++;
            }
            else
                nums[i++] = nums[j++];
        }
        return i;
    }
};