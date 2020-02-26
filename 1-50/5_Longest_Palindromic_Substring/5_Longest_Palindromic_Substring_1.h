#include <string>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
  public:
    set<int> impossible_sum;
    string longestPalindrome(string s)
    {
        impossible_sum.erase(impossible_sum.begin(), impossible_sum.end());
        unordered_map<char, set<int>> char_index_map;
        int sz = s.size();
        int maxlen = 0, start_point = 0;
        for (int i = 0; i < sz; ++i)
        {
            char_index_map[s[i]].insert(i);
            for (auto index : char_index_map[s[i]])
            {
                if (i - index + 1 <= maxlen)
                    break;
                if (IsPalindrome(s, index, i))
                {
                    maxlen = i - index + 1;
                    start_point = index;
                    break;
                }
            }
        }
        return s.substr(start_point, maxlen);
    }

    bool IsPalindrome(const string &str, int beg, int end)
    {
        int sum = beg + end;
        if (impossible_sum.find(sum) != impossible_sum.end())
            return false;
        for (int i = beg, j = end; i < j; ++i, --j)
        {
            if (str[i] != str[j])
            {
                impossible_sum.insert(sum);
                return false;
            }
        }
        return true;
    }
};