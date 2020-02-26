#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        return recursiveCheck(s1, s2);
    }

private:
    unordered_map<string, bool> checked;

    bool recursiveCheck(string s1, string s2)
    {
        if (s1 == s2)
            return checked[s1 + s2] = true;

        string s12 = s1 + s2;
        if (checked.find(s12) != checked.end())
            return checked[s12];

        int sz = s1.length();
        int chars[26] = {0};
        for (int i = 0; i < sz; i++)
        {
            ++chars[s1[i] - 'a'];
            --chars[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; i++)
            if (chars[i] != 0)
                return checked[s12] = false;

        for (int sp = 1; sp < sz; sp++)
        {
            if ((recursiveCheck(s1.substr(0, sp), s2.substr(0, sp)) && recursiveCheck(s1.substr(sp, sz - sp), s2.substr(sp, sz - sp))) ||
                (recursiveCheck(s1.substr(0, sp), s2.substr(sz - sp, sp)) && recursiveCheck(s1.substr(sp, sz - sp), s2.substr(0, sz - sp))))
                return checked[s12] = true;
        }
        return checked[s12] = false;
    }
};