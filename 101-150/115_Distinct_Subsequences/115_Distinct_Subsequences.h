#include <string>
#include <vector>
using namespace std;
//memorize

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int ssz = s.size();
        int tsz = t.size();
        vector<vector<int>> dp(ssz + 1, vector<int>(tsz + 1, -1));

        for (int j = 1; j <= tsz; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= ssz; i++)
            dp[i][0] = 1;

        return numDistinct(s, t, ssz, tsz, dp);
    }

private:
    int numDistinct(string &s, string &t, int ls, int lt, vector<vector<int>> &dp)
    {
        if (dp[ls][lt] != -1)
            return dp[ls][lt];

        return dp[ls][lt] = numDistinct(s, t, ls - 1, lt, dp) + (s[ls - 1] == t[lt - 1] ? numDistinct(s, t, ls - 1, lt - 1, dp) : 0);
    }
};