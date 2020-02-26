#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        map<int, vector<int>> rectangles;
        map<int, int> maxwidths;
        int b = 0, e = 0;
        int sz = heights.size();
        while (b < sz)
        {
            e = b + 1;
            while (e < sz && heights[e] == heights[b])
                e++;
            rectangles[heights[b]].push_back(b);
            rectangles[heights[b]].push_back(e);
            if (maxwidths.find(heights[b]) == maxwidths.end())
                maxwidths[heights[b]] = e - b;
            else
                maxwidths[heights[b]] = max(maxwidths[heights[b]], e - b);
            b = e;
        }

        vector<int> intervals;
        int maxwidth = 0;
        int maxarea = 0;
        for (auto it = rectangles.rbegin(); it != rectangles.rend(); it++)
        {
            int height = (*it).first;
            maxwidth = max(maxwidth, maxwidths[height]);
            vector<int> &hrecs = (*it).second;
            //merge
            int i = 0, j = 0;
            while (i < intervals.size() && j < hrecs.size())
            {
                if (intervals[i] < hrecs[j])
                {
                    if (i - 1 > 0 && intervals[i - 1] == intervals[i])
                    {
                        intervals[i - 1] = intervals[i + 1];
                        intervals.erase(intervals.begin() + i);
                        intervals.erase(intervals.begin() + i);
                        maxwidth = max(maxwidth, intervals[i - 1] - intervals[i - 2]);
                    }
                    else
                        i += 2;
                }
                else
                {
                    if (i - 1 > 0 && intervals[i - 1] == hrecs[j])
                    {
                        intervals[i - 1] = hrecs[j + 1];
                        maxwidth = max(maxwidth, intervals[i - 1] - intervals[i - 2]);
                    }
                    else
                    {
                        intervals.insert(intervals.begin() + i, hrecs[j]);
                        intervals.insert(intervals.begin() + i + 1, hrecs[j + 1]);
                        i += 2;
                    }
                    j += 2;
                }
            }
            if (j < hrecs.size())
            {
                if (i - 1 > 0 && intervals[i - 1] == hrecs[j])
                {
                    intervals[i - 1] = hrecs[j + 1];
                    maxwidth = max(maxwidth, intervals[i - 1] - intervals[i - 2]);
                    j += 2;
                }
                while (j < hrecs.size())
                    intervals.push_back(hrecs[j++]);
            }
            else if (i < intervals.size())
            {
                if (i - 1 > 0 && intervals[i - 1] == intervals[i])
                {
                    intervals[i - 1] = intervals[i + 1];
                    intervals.erase(intervals.begin() + i);
                    intervals.erase(intervals.begin() + i);
                    maxwidth = max(maxwidth, intervals[i - 1] - intervals[i - 2]);
                }
            }
            maxarea = max(maxarea, maxwidth * height);
        }
        return maxarea;
    }
};