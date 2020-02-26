#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> nums = {0};
        for (int bit = 0; bit < n; bit++)
        {
            int i = nums.size() - 1;
            while (i >= 0)
                nums.push_back(nums[i--] ^ (1 << bit));
        }
        return nums;
    }
};