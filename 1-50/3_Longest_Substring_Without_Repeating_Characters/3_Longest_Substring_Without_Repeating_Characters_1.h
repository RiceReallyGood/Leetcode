//use deque
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        deque<char> subs;
        int maxlen = 0;
        for (auto ch : s)
        {
            subs.push_back(ch);
            subs.erase(subs.begin(), find(subs.rbegin() + 1, subs.rend(), ch).base());
            if (subs.size() > maxlen)
                maxlen = subs.size();
        }
        return maxlen;
    }
};