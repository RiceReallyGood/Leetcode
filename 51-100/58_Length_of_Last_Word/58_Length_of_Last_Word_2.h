#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int LastLen = 0;
        int index = s.length() - 1;
        while (index >= 0 && s[index] == ' ')
            index--;
        while (index >= 0 && s[index] != ' ')
        {
            LastLen++;
            index--;
        }
        return LastLen;
    }
};