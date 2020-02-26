#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 2));
        for(int h = 1; h <= N + 1; h++)
            dp[1][h] = h - 1;
        
        for(int egg = 2; egg <= K; egg++){
            dp[egg][1] = 0;
            for(int h = 2; h <= N + 1; h++){
                //find l
                int l = 1, r = h - 1;
                while(l < r){
                    int c = (l + r) / 2;
                    if(dp[egg][c] < dp[egg - 1][h - c])
                        l = c + 1;
                    else
                        r = c;
                }
                if(l == 1 || dp[egg][l] == dp[egg - 1][h - l])
                    dp[egg][h] = dp[egg][l] + 1;
                else
                    dp[egg][h] = min(dp[egg][l], dp[egg - 1][h + 1 - l]);
                /* for(int l = 1; l < h; l++){
                    dp[egg][h] = min(dp[egg][h], max(dp[egg][l], dp[egg - 1][h - l]) + 1);
                } */
            }
        }
        return dp[K][N + 1];
    }
};

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 1);
        int count = 0;
        while(dp.back() < N + 1){
            int prev = 1, curr;
            for(int e = 1; e <= K; e++){
                curr = dp[e];
                dp[e] += prev;
                prev = curr;
            }
            count++;
        }
        return count;
    }
};