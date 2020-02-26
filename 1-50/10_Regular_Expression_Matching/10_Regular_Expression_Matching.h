#include <string>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int ssz = s.size(), psz = p.size();
        bool *PartMatch = new bool[(ssz + 1) * (psz + 1)];
        PartMatch[(ssz + 1) * (psz + 1) - 1] = true;
        if(psz > 0)
            PartMatch[ssz * (psz + 1) + psz - 1] = false;

        for (int j = psz - 2; j >= 0; --j)
        {
            if (p[j + 1] == '*')
                PartMatch[ssz * (psz + 1) + j] = PartMatch[ssz * (psz + 1) + j + 2];
            else
                PartMatch[ssz * (psz + 1) + j] = false;
        }

        for (int i = ssz - 1; i >= 0; --i)
        {
            PartMatch[i * (psz + 1) + psz] = false;
        }

        for (int i = ssz - 1; i >= 0; --i)
        {
            for (int j = psz - 1; j >= 0; --j)
            {
                bool FirstMatch = (s[i] == p[j] || p[j] == '.');
                if (j + 1 < psz && p[j + 1] == '*')
                    PartMatch[i * (psz + 1) + j] = (PartMatch[i * (psz + 1) + j + 2] || (FirstMatch && PartMatch[(i + 1) * (psz + 1) + j]));
                else
                {
                    PartMatch[i * (psz + 1) + j] = (FirstMatch && PartMatch[(i + 1) * (psz + 1) + j + 1]);
                }
            }
        }
        return PartMatch[0];
    }
};