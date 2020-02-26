#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        int sz = nums.size();
        for (int k = 1; k <= sz; k++)
        {
            vector<int> indexstack;
            for (int i = 0; i < k; i++)
                indexstack.push_back(i);

            while (true)
            {
                while (indexstack.back() < sz)
                {
                    ret.push_back(index2nums(indexstack, nums));
                    indexstack.back()++;
                }
                while (!indexstack.empty() && indexstack.back() + k - indexstack.size() >= sz - 1)
                    indexstack.pop_back();

                if (indexstack.empty())
                    break;

                indexstack.back()++;
                while (indexstack.size() < k)
                    indexstack.push_back(indexstack.back() + 1);
            }
        }
        return ret;
    }

    vector<int> index2nums(vector<int> &indices, vector<int> &nums)
    {
        vector<int> ret;
        for (int i = 0; i < indices.size(); i++)
            ret.push_back(nums[indices[i]]);
        return ret;
    }
};