#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int ssz = s.size(), psz = p.size();
        vector<vector<bool>> PartMatch(ssz + 1, vector<bool>(psz + 1, false));
        PartMatch[ssz][psz] = true;
        //if(psz>0)
        //PartMatch[ssz][psz-1] = false;

        for (int j = psz - 2; j >= 0; j--)
            if (p[j + 1] == '*')
                PartMatch[ssz][j] = PartMatch[ssz][j + 2];
        //else
        //    PartMatch[ssz][j] = false;

        if (ssz && psz)
            PartMatch[ssz - 1][psz - 1] = (p[psz - 1] == '.' || s[ssz - 1] == p[psz - 1]);

        for (int i = ssz - 1; i >= 0; i--)
        {
            //PartMatch[i][psz] = false;
            for (int j = psz - 2; j >= 0; j--)
            {
                if (p[j + 1] == '*')
                    PartMatch[i][j] = PartMatch[i][j + 2] || (PartMatch[i + 1][j] && (p[j] == '.' || p[j] == s[i]));
                else
                    PartMatch[i][j] = PartMatch[i + 1][j + 1] && (p[j] == '.' || p[j] == s[i]);
            }
        }

        return PartMatch[0][0];
    }
};