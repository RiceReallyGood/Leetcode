#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return vector<vector<int>>();
        return merge2(intervals, 0, intervals.size() - 1);
    }

    vector<vector<int>> merge2(vector<vector<int>> &intervals, int l, int r)
    {
        if (l == r)
            return vector<vector<int>>(1, intervals[l]);
        vector<vector<int>> ret;
        int c = (l + r) / 2;
        vector<vector<int>> v1 = merge2(intervals, l, c);
        vector<vector<int>> v2 = merge2(intervals, c + 1, r);
        int i = 0, j = 0;
        int left = 1, right = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (left > right)
            {
                if (v1[i][0] < v2[j][0])
                {
                    left = v1[i][0];
                    right = v1[i][1];
                    i++;
                }
                else
                {
                    left = v2[j][0];
                    right = v2[j][1];
                    j++;
                }
            }
            else
            {
                if (v1[i][0] <= right)
                {
                    right = max(right, v1[i][1]);
                    i++;
                }
                else if (v2[j][0] <= right)
                {
                    right = max(right, v2[j][1]);
                    j++;
                }
                else
                {
                    ret.push_back({left, right});
                    left = 1;
                    right = 0;
                }
            }
        }
        if (i == v1.size())
        {
            while (j < v2.size() && v2[j][0] <= right)
            {
                right = max(right, v2[j][1]);
                j++;
            }
            ret.push_back({left, right});
            while (j < v2.size())
                ret.push_back(v2[j++]);
        }
        else
        {
            while (i < v1.size() && v1[i][0] <= right)
            {
                right = max(right, v1[i][1]);
                i++;
            }
            ret.push_back({left, right});
            while (i < v1.size())
                ret.push_back(v1[i++]);
        }
        return ret;
    }
};