#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> startindex;
        int N = intervals.size();
        for(int i = 0; i < N; i++)
            startindex[intervals[i][0]] = i;
        vector<int> ret(N, -1);
        for(int i = 0; i < N; i++){
            auto it = startindex.lower_bound(intervals[i][1]);
            if(it != startindex.end()) ret[i] = (*it).second;
        }
        return ret;
    }
};