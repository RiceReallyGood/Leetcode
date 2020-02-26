#include <string>
#include <vector>
using namespace std;
//DP

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        if (s1.empty())
            return true;
        int sz = s1.size();
        vector<vector<vector<bool>>> dp(sz, vector<vector<bool>>(sz, vector<bool>(sz, false)));
        if (!isPermutation(s1, 0, s2, 0, sz))
            return false;
        //len == 1
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                dp[0][i][j] = s1[i] == s2[j];

        for (int len = 2; len <= sz; len++)
        {
            for (int i = 0; i <= sz - len; i++)
            {
                for (int j = 0; j <= sz - len; j++)
                {
                    if (!isPermutation(s1, i, s2, j, len))
                        continue;

                    for (int sp = 1; sp < len; sp++)
                    {
                        dp[len - 1][i][j] = (dp[sp - 1][i][j] && dp[len - sp - 1][i + sp][j + sp]) ||
                                            (dp[sp - 1][i][j + len - sp] && dp[len - sp - 1][i + sp][j]);
                        if (dp[len - 1][i][j])
                            break;
                    }
                }
            }
        }
        return dp[sz - 1][0][0];
    }

    bool isPermutation(string &s1, int start1, string &s2, int start2, int len)
    {
        vector<int> chars(26, 0);
        for (int i = 0; i < len; i++)
            chars[s1[start1 + i] - 'a']++;

        for (int i = 0; i < len; i++)
            chars[s2[start2 + i] - 'a']--;

        for (int i = 0; i < 26; i++)
            if (chars[i] != 0)
                return false;

        return true;
    }
};