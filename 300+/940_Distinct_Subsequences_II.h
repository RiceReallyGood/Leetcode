#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string S) {
        vector<long> dp(26, 0);
        long ret = 0;
        for(int i = 0; i < S.length(); i++){
            long temp = dp[S[i] - 'a'];
            dp[S[i] - 'a'] = ret + 1;
            ret = (ret + dp[S[i] - 'a'] - temp) % 1000000007L;
        }
        return (ret + 1000000007L) % 1000000007L;
    }
};