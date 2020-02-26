#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comp = [](vector<int>& v1, vector<int>& v2){
            //return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
            return v1[0] < v2[0];
        };
        sort(points.begin(), points.end(), comp);
        int rightbound = INT_MAX;
        int count = 0;
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] > rightbound){
                count++;
                rightbound = points[i][1];
            }
            else
                rightbound = min(rightbound, points[i][1]);
        }
        if(!points.empty())
            count++;
        return count;
    }
};