#include <string>
#include <vector>
using namespace std;
//DP

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int ssz = s.size();
        int tsz = t.size();
        long dp[tsz + 1] = {0};
        dp[0] = 1;
        for (int i = 1; i < ssz; i++)
        {
            for (int j = tsz; j >= 1; j++)
                if (s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
        }
        return dp[tsz];
    }
};