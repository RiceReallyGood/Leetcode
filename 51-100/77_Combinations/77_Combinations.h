#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> istack;
        for (int i = 1; i <= k; i++)
            istack.push_back(i);
        while (true)
        {
            while (istack.back() <= n)
            {
                ret.push_back(istack);
                istack.back()++;
            }
            while (!istack.empty() && istack.back() + (k - istack.size()) >= n)
                istack.pop_back();
            if (istack.empty())
                break;

            istack.back()++;
            while (istack.size() < k)
                istack.push_back(istack.back() + 1);
        }
        return ret;
    }
};