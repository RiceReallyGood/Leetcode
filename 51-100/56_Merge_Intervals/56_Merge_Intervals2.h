#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;
        auto cmp = [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0, j = 1;
        while (j < intervals.size())
        {
            if (intervals[j][0] <= intervals[i][1])
                intervals[i][1] = max(intervals[i][1], intervals[j++][1]);
            else
                intervals[++i] = intervals[j++];
        }
        intervals.resize(i + 1);
        return intervals;
    }
};