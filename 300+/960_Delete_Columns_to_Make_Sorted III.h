#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int sz = A.size();
        int n = A[0].length();
        vector<int> dp(n, 1);
        int maxlen = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0/* j + 2 > dp[i] */; j--){ //固定条件的for循环更快。。。。不知道为什么。。
                if(dp[j] + 1 <= dp[i]) continue;
                int k = 0;
                for(; k < sz; k++)
                    if(A[k][j] > A[k][i]) break;
                if(k == sz) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxlen = max(maxlen, dp[i]);
        }
        return n - maxlen;
    }
};