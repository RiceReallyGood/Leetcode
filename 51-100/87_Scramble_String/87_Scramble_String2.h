#include <string>
using namespace std;
//recursive

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        if (s1.length() != s2.length())
            return false;
        int sz = s1.size();
        int chars[26] = {0};

        for (int i = 0; i < sz; i++)
        {
            ++chars[s1[i] - 'a'];
            --chars[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; i++)
            if (chars[i] != 0)
                return false;

        for (int sp = 1; sp < sz; sp++)
        {
            if ((isScramble(s1.substr(0, sp), s2.substr(0, sp)) && isScramble(s1.substr(sp, sz - sp), s2.substr(sp, sz - sp))) ||
                (isScramble(s1.substr(0, sp), s2.substr(sz - sp, sp)) && isScramble(s1.substr(sp, sz - sp), s2.substr(0, sz - sp))))
                return true;
        }

        return false;
    }
};