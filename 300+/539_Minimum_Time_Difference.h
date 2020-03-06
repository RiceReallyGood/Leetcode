#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() > 1440) return 0;
        vector<bool> exist(1440, false);
        for(int i = 0; i < timePoints.size(); i++){
            int t = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
            if(exist[t]) return 0;
            exist[t] = true;
        }
        
        int earliesttime = -1;
        int i = 0, j = 0;
        while(!exist[j]) j++;
        earliesttime = j;
        int mindiff = 1440;
        for(i = j, j++;; j++){
            while(j < 1440 && !exist[j]) j++;
            if(j == 1440) break;
            mindiff = min(mindiff, j - i);
            i = j;
        }
        mindiff = min(mindiff, earliesttime + 1440 - i);
        return mindiff;
    }
};