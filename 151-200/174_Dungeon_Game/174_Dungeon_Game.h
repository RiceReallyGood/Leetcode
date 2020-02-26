#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<int> dp(cols, 0);
        dp[cols - 1] = max(1 - dungeon[rows - 1][cols - 1], 1);
        for(int i = cols - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1] - dungeon[rows - 1][i], 1);
        
        for(int i = rows - 2; i >= 0; i--){
            vector<int> temp(cols, 0);
            temp[cols - 1] = max(dp[cols - 1] - dungeon[i][cols - 1], 1);
            for(int j = cols - 2; j >= 0; j--)
                temp[j] = max(min(dp[j], temp[j + 1]) - dungeon[i][j], 1);
            swap(temp, dp);
        }

        return  dp[0];
    }
};