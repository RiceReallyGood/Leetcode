#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int CurrIndex = 0, NextIndex = 0;
        int index = 1;
        while (true)
        {
            int RightBound = CurrIndex + nums[CurrIndex];
            if (RightBound >= nums.size() - 1)
                return true;
            for (; index <= RightBound; index++)
            {
                if (index + nums[index] > NextIndex + nums[NextIndex])
                    NextIndex = index;
            }
            if (NextIndex == CurrIndex)
                return false;
            else
                CurrIndex = NextIndex;
        }
        return false;
    }
};