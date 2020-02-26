#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        vector<int> t_chars(128, 0);
        for (int i = 0; i < t.size(); ++i)
            ++t_chars[t[i]];

        int count = 0;
        int i = 0, j = 0;
        vector<int> subs_chars(128, 0);
        for (; j < s.size() && count < t.size(); ++j)
        {
            if (t_chars[s[j]] != 0)
            {
                if (subs_chars[s[j]] < t_chars[s[j]])
                    ++count;
                ++subs_chars[s[j]];
            }
        }
        if (count < t.size())
            return "";
        while (t_chars[s[i]] == 0 || t_chars[s[i]] > subs_chars[s[i]])
        {
            --subs_chars[s[i]];
            ++i;
        }
        if (j == s.size())
            return s.substr(i, j - i);

        int first_index = i, minlen = j - i;
        for (; j < s.size(); ++j)
        {
            if (t_chars[s[j]] == 0)
                continue;

            ++subs_chars[s[j]];
            while (t_chars[s[i]] == 0 || t_chars[s[i]] > subs_chars[s[i]])
            {
                --subs_chars[s[i]];
                ++i;
            }
            if (j - i + 1 < minlen)
            {
                first_index = i;
                minlen = j - i + 1;
            }
        }
        return s.substr(first_index, minlen);
    }
};