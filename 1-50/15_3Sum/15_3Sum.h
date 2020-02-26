#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        map<int, int> nums_count;
        for (auto i : nums)
        {
            if (nums_count.find(i) != nums_count.end())
                ++nums_count[i];
            else
                nums_count[i] = 1;
        }

        for (auto it1 = nums_count.begin(); it1 != nums_count.end(); ++it1)
        {
            if ((*it1).first > 0)
                break;
            if ((*it1).first == 0)
            {
                if ((*it1).second > 2)
                    ret.push_back({0, 0, 0});
                break;
            }
            if ((*it1).second > 1 && nums_count.find(-2 * (*it1).first) != nums_count.end())
                ret.push_back({(*it1).first, (*it1).first, -2 * (*it1).first});
            auto it2 = it1;
            ++it2;
            if (it2 == nums_count.end() || (*it1).first + (*it2).first >= 0)
                break;
            for (; it2 != nums_count.end(); ++it2)
            {
                int rest = -((*it1).first + (*it2).first);
                if (rest < (*it2).first)
                    break;
                if (rest == (*it2).first)
                {
                    if ((*it2).second > 1)
                        ret.push_back({(*it1).first, (*it2).first, rest});
                }
                else
                {
                    if (nums_count.find(rest) != nums_count.end())
                        ret.push_back({(*it1).first, (*it2).first, rest});
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int l = nums.size();
        if (l < 3) return ans;
        sort(nums.begin(), nums.end()); 
        int i = 0;
        while (i < l && nums[i] < 0) 
            i++;
        if (i == l) return ans;
        for(int j = 0; j <= i; j++) {
            int s = l - 1;
            for(int k = j + 1; k < s; k++) {
                int temp = nums[j] + nums[k];
                while (s > k + 1 && nums[s] > -temp) 
                    s--;
                if (nums[s] == -temp) {
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(nums[s]);
                    ans.push_back(v);
                    v.clear();
                }
                while (k + 1 < l && nums[k + 1] == nums[k]) 
                    k++;
            }
            while ( j + 1 < l && nums[j + 1] == nums[j]) 
                j++;
        }
        return ans;
    }
};