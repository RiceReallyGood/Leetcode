#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 1;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        if(s[0] == '*') dp[1] = 9;
        else dp[1] = s[0] == '0' ? 0 : 1;

        for(int i = 1; i < n; i++){
            if(s[i] == '*'){
                if(s[i - 1] == '*')
                    dp[i + 1] = (15 * dp[i - 1] + 9 * dp[i]) % 1000000007L;
                else if(s[i - 1] == '1')
                    dp[i + 1] = (9 * dp[i - 1] + 9 * dp[i]) % 1000000007L;
                else if(s[i - 1] == '2')
                    dp[i + 1] = (6 * dp[i - 1] + 9 * dp[i]) % 1000000007L;
                else
                    dp[i + 1] = (9 * dp[i])  % 1000000007L;
            }
            else{
                if(s[i - 1] == '*'){
                    if(s[i] == '0')
                        dp[i + 1] = 2 * dp[i - 1] % 1000000007L;
                    else if(s[i] > '0' && s[i] <= '6')
                        dp[i + 1] = (2 * dp[i - 1] + dp[i])  % 1000000007L;
                    else
                        dp[i + 1] = (dp[i - 1] + dp[i])  % 1000000007L;
                }
                else{
                    if(s[i] == '0'){
                        if(s[i - 1] == '1' || s[i - 1] == '2')
                            dp[i + 1] = dp[i - 1];
                        else
                            dp[i + 1] = 0;
                    }
                    else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                        dp[i + 1] = (dp[i - 1] + dp[i]) % 1000000007L;
                    else
                        dp[i + 1] = dp[i];
                }
            }
        }
        return dp[n];
    }
};