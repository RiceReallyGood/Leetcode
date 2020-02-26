#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int ssz = s.size(), psz = p.size();
        bool *PartMatch = new bool[(ssz + 1) * (psz + 1)];
        PartMatch[0] = true;

        for (int i = 1; i <= ssz; i++)
            PartMatch[i * (psz + 1)] = false;

        for (int j = 1; j <= psz; j++)
            PartMatch[j] = (PartMatch[j - 1] && p[j - 1] == '*');

        for (int i = 1; i <= ssz; ++i)
        {
            for (int j = 1; j <= psz; ++j)
            {
                if (p[j - 1] == '*')
                {
                    PartMatch[i * (psz + 1) + j] = (PartMatch[(i - 1) * (psz + 1) + j] || PartMatch[i * (psz + 1) + j - 1]);
                }
                else
                {
                    PartMatch[i * (psz + 1) + j] = (PartMatch[(i - 1) * (psz + 1) + j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?'));
                }
            }
        }
        return PartMatch[(ssz + 1) * (psz + 1) - 1];
    }
};