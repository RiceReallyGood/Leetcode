#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        auto comparePair = [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] < v2[0] ? true : (v1[0] > v2[0] ? false : v1[1] < v2[1]);
        };

        sort(intervals.begin(), intervals.end(), comparePair);

        int nIntervals = 0;
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> &lastInterval = intervals[nIntervals];
            vector<int> &currInterval = intervals[i];

            if (lastInterval[1] >= currInterval[0]) {
                lastInterval[1] = max(lastInterval[1], currInterval[1]);
            } else {
                ++nIntervals;
                if (nIntervals != i) {
                    intervals[nIntervals] = intervals[i];
                }
            }
        }

        intervals.resize(nIntervals + 1);
        return intervals;
    }
};