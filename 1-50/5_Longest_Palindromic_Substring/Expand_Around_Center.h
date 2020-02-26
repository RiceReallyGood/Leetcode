#include <string>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int sz = s.size();
        int maxlen = 0, start_point = 0;
        for (int sum = 0; sum < 2 * sz - maxlen - 1; ++sum)
        {
            int i = sum / 2, j = sum - i;
            bool check;
            if (i == j)
                check = true;
            else
                check = (s[i] == s[j]);
            while (check && i > 0 && j < sz - 1)
            {
                check = (s[--i] == s[++j]);
            }
            if (check && j - i + 1 > maxlen)
            {
                maxlen = j - i + 1;
                start_point = i;
            }
            else if (!check && j - i - 1 > maxlen)
            {
                maxlen = j - i - 1;
                start_point = i + 1;
            }
        }
        return s.substr(start_point, maxlen);
    }
};