// dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
// if(s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j  - 1] + 2)
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l <= r){
            if(s[l] != s[r]) break;
            l++; r--;
        }
        if(l > r) return n;
        vector<int> dp(n);
        for(int i = n - 1; i >= 0; i--){
            dp[i] = 1;
            int temp = 0, temp2;
            for(int j = i + 1; j < n; j++){
                temp2 = dp[j];
                if(s[i] == s[j]) dp[j] = temp + 2;
                else dp[j] = max(dp[j - 1], dp[j]);
                temp = temp2;
            }
        }
        return dp.back();
    }
};