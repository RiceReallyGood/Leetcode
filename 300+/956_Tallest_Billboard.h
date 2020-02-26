#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for(int h : rods) sum += h;
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;
        sum = 0;
        for(int i = 0; i < rods.size(); i++){
            vector<int> temp(dp);
            for(int s = 0; s <= sum; s++){
                if(dp[s] == -1) continue;
                if(s > rods[i]) temp[s - rods[i]] = max(temp[s - rods[i]], dp[s] + rods[i]);
                else temp[rods[i] - s] = max(temp[rods[i] - s], dp[s] + rods[i]);
                temp[s + rods[i]] = max(temp[s + rods[i]], dp[s] + rods[i]);
            }
            swap(dp, temp);
            sum += rods[i];
        }
        return dp[0] / 2;
    }
};