#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 1 || nums[i] > n)
                continue;
            else
            {
                if (nums[i] < i + 1)
                    nums[nums[i] - 1] = nums[i];
                else if (nums[i] > i + 1)
                {
                    int num = nums[i];
                    while (num > 0 && num < n + 1)
                    {
                        if (nums[num - 1] == num)
                            break;
                        int temp = nums[num - 1];
                        nums[num - 1] = num;
                        num = temp;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};