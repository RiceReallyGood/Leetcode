#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int rightbound = INT_MIN;
        int count = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= rightbound){
                count++;
                rightbound = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};