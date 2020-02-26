#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        while (true)
        {
            int i = nums.size() - 2;
            while (i >= 0 && nums[i] > nums[i + 1])
                i--;
            if (i == -1)
                break;
            int j = nums.size() - 1;
            while (nums[j] < nums[i])
                j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            for (i = i + 1, j = nums.size() - 1; i < j; i++, j--)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            ret.push_back(nums);
        }
        return ret;
    }
};