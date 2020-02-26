#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nmap.find(target - nums[i]) == nmap.end())
            {
                nmap[nums[i]] = i;
            }
            else
            {
                return vector<int>{nmap.find(target - nums[i])->second, i};
            }
        }
        return {0, 0};
    }
};