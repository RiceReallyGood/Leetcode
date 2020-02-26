#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ret;
        ret.push_back({});
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int len = 1; len <= sz; len++)
        {
            vector<int> indices;
            for (int i = 0; i < len; i++)
                indices.push_back(i);
            ret.push_back(Indices2Nums(indices, nums));

            while (true)
            {
                while (!indices.empty())
                {
                    int NextIndex = next_neq_index(nums, indices.back());
                    if (NextIndex + len - indices.size() >= nums.size())
                        indices.pop_back();
                    else
                    {
                        indices.back() = NextIndex;
                        break;
                    }
                }

                if (indices.empty())
                    break;
                while (indices.size() < len)
                    indices.push_back(indices.back() + 1);

                ret.push_back(Indices2Nums(indices, nums));
            }
        }
        return ret;
    }

    vector<int> Indices2Nums(vector<int> &indices, vector<int> &nums)
    {
        vector<int> ret;
        for (auto it = indices.begin(); it != indices.end(); it++)
            ret.push_back(nums[*it]);
        return ret;
    }

    int next_neq_index(vector<int> &nums, int index)
    {
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[next - 1])
            next++;
        return next;
    }
};

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> vv;
        vector<int> v;
        sort(nums.begin(), nums.end());
        PowerSet(vv, v, nums, 0);

        return vv;
    }

    void PowerSet(vector<vector<int>> &vv, vector<int> &v, vector<int> &nums, int begin)
    {
        if (true)
        {
            vv.push_back(v);
        }

        for (int i = begin; i < nums.size(); i++)
        {
            if ((i > begin) && (nums[i] == nums[i - 1]))
            {
                continue;
            }
            else
            {
                v.push_back(nums[i]);
                PowerSet(vv, v, nums, i + 1);
                v.pop_back();
            }
        }
    }
};