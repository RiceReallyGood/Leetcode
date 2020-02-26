#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3)
            return false;

        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1));

        dp[0][0] = true;
        for (int m = 1; m <= len1; m++)
            dp[m][0] = dp[m - 1][0] && s1[m - 1] == s3[m - 1];
        for (int n = 1; n <= len2; n++)
            dp[0][n] = dp[0][n - 1] && s2[n - 1] == s3[n - 1];

        for (int m = 1; m <= len1; m++)
        {
            for (int n = 1; n <= len2; n++)
                dp[m][n] = (dp[m - 1][n] && s1[m - 1] == s3[m + n - 1]) || (dp[m][n - 1] && s2[n - 1] == s3[m + n - 1]);
        }

        return dp[len1][len2];
    }
};