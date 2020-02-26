#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lastgood = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= lastgood)
                lastgood = i;
        }
        return lastgood == 0;
    }
};