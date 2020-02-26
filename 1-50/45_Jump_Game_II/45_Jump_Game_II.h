#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int i = 0, j = 0;
        int NextIndex = 0;
        while (i < nums.size() - 1)
        {
            if (i + nums[i] < nums.size() - 1)
            {
                while (j <= i + nums[i])
                {
                    if (j + nums[j] > NextIndex + nums[NextIndex])
                        NextIndex = i;
                    j++;
                }
                i = NextIndex;
            }
            else
            {
                i = nums.size() - 1;
            }
            step++;
        }
        return step;
    }
};