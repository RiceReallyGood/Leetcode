#include <vector>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int bound = 0;
        for(int w : stones)
            bound += w;
        bound = (bound + 1) / 2;
        vector<bool> dp(bound + 1, false);
        dp[stones[0]] = true;
        for(int i = 1; i < stones.size(); i++){
            vector<bool> temp(bound + 1, false);
            for(int j = 0; j <= bound; j++){
                if(!dp[j]) continue;
                temp[std::abs(stones[i] - j)] = true;
                if(stones[i] + j <= bound)
                    temp[stones[i] + j] = true;
            }
            swap(temp, dp);
        }
        for(int i = 0; i <= bound; i++)
            if(dp[i]) return i;
        return -1;
    }
};


class Solution { //16ms
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> dp = {stones[0]};
        for(int i = 1; i < stones.size(); i++){
            set<int> temp;
            for(auto n : dp){
                temp.insert(abs(stones[i] - n));
                temp.insert(stones[i] + n);
            }
            swap(temp, dp);
        }
        return *(dp.begin());
    }
};