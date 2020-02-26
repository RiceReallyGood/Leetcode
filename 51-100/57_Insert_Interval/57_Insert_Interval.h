#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
            i++;
        if (i == intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int CurIndex = i;
        int RightBound = newInterval[1];
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
            i++;
        int sz = intervals.size();
        int newsize = sz + 1 - i + CurIndex;
        if (CurIndex == i)
        {
            intervals.resize(newsize);
            for (int j = newsize - 1; j > CurIndex; j--)
                intervals[j] = intervals[j - 1];
            intervals[CurIndex] = newInterval;
        }
        else
        {
            int shift = i - CurIndex - 1;
            intervals[CurIndex][0] = min(intervals[CurIndex][0], newInterval[0]);
            intervals[CurIndex][1] = max(newInterval[1], intervals[i - 1][1]);
            for (int j = i; j < intervals.size(); j++)
            {
                intervals[j - shift] = intervals[j];
            }
            intervals.resize(newsize);
        }
        return intervals;
    }
};