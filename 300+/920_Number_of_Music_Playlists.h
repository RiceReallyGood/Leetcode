#include <vector>
using namespace std;


class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        long mod = 1e9 + 7;
        vector<long> dp(N - K, 0);
        long prod = 1;
        for(int i = 0; i <= K; i++)
            prod = prod * (N - i) % mod;
        dp[0] = prod;

        for(int len = K + 2; len <= L; len++){
            for(int i = N - K - 1; i > 0; i--)
                dp[i] = ((N- (K + i)) * dp[i - 1] + (i + 1) * dp[i]) % mod;
        }
        return dp.back();
    }
};