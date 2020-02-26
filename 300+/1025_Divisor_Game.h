#include <vector>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        for(int i = 1; i < N; i++){
            if(dp[i] == true) continue;
            int bound = min(i, N - i);
            for(int j = 1; j <= bound; j++){
                if((i + j) % j == 0)
                    dp[i + j] = true;
            }
        }
        return dp[N];
    }
};

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};