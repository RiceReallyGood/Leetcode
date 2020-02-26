//use unordered_map
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> chmap;
        int sz = s.size();
        int maxlen = 0;
        for (int i = 0, j = 0; j < sz; ++j)
        {
            if (chmap.find(s[j]) != chmap.end())
                i = max(i, chmap[s[j]] + 1);
            chmap[s[j]] = j;
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};