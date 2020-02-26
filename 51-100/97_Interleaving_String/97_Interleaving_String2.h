#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {

        if (s1.length() > s2.length())
            swap(s1, s2);
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3)
            return false;

        vector<bool> dp(len1 + 1, false);

        dp[0] = true;
        for (int m = 1; m <= len1; m++)
            dp[m] = dp[m - 1] && s1[m - 1] == s3[m - 1];

        for (int n = 1; n <= len2; n++)
        {
            dp[0] = dp[0] && s2[n - 1] == s3[n - 1];
            for (int m = 1; m <= len1; m++)
                dp[m] = (dp[m - 1] && s1[m - 1] == s3[n + m - 1]) || (dp[m] && s2[n - 1] == s3[m + n - 1]);
        }

        return dp[len1 + 1];
    }
};