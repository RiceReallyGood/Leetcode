#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int LastLen = 0;
        int index = 0;
        while (index < s.length())
        {
            if (s[index] == ' ')
            {

                while (index < s.length() && s[index] == ' ')
                    index++;
                if (index < s.length())
                {
                    LastLen = 1;
                    index++;
                }
            }
            else
            {
                LastLen++;
                index++;
            }
        }
        return LastLen;
    }
};