#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        };
        sort(clips.begin(), clips.end(), comp);
        vector<int> dp(101, INT_MAX);
        dp[0] = 0;
        int righibound = 0;
        for(int i = 0; i < clips.size() && righibound < T; i++){
            if(dp[clips[i][0]] == INT_MAX) return -1;
            if(clips[i][1] <= righibound) continue;
            for(int j = clips[i][1]; j > righibound; j--)
                dp[j] = dp[clips[i][0]] + 1;
            righibound = clips[i][1];    
        }
        return dp[T] == INT_MAX ? -1 : dp[T];
    }
};