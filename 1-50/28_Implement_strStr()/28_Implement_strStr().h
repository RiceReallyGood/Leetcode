#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        vector<int> next(needle.size(), 0);
        next[0] = -1;
        int i = 1, j = 0;
        while (i < next.size())
        {
            if (needle[i] == needle[j])
                next[i] = next[j];
            else
            {
                next[i] = j;
                while (j != -1 && needle[j] != needle[i])
                    j = next[j];
            }
            i++;
            j++;
        }

        i = 0, j = 0;
        while (i < haystack.size())
        {
            if (j == needle.size())
                break;
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};