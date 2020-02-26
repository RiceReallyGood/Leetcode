#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int ret = 0;
        int current_max = 0;
        unordered_map<char, int> Roman =
            {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (Roman[s[i]] >= current_max)
            {
                current_max = Roman[s[i]];
                ret += Roman[s[i]];
            }
            else
            {
                ret -= Roman[s[i]];
            }
        }
        return ret;
    }
};