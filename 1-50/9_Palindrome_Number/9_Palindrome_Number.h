#include <string>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string str;
        int digit = 0;
        while (x)
        {
            digit = x % 10;
            x /= 10;
            str.push_back('0' + digit);
        }
        for (int i = 0, j = str.size() - 1; i < j; ++i,--j)
        {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }
};