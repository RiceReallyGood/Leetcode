#include <string>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        auto notspace = [](char c) { return !(c == ' '); };
        auto notdigit = [](char c) { return !isdigit(c); };
        str.erase(str.begin(), find_if(str.begin(), str.end(), notspace));
        str.erase(find_if(str.begin() + 1, str.end(), notdigit), str.end());
        if (str.size() == 0)
            return 0;
        else if (str.size() == 1 && !isdigit(str[0]))
            return 0;
        int sign = 1;
        if (str[0] == '-')
        {
            sign = -1;
            str.erase(0, 1);
        }
        else if (str[0] == '+')
        {
            str.erase(0, 1);
        }
        if (!isdigit(str[0]))
            return 0;
        int num = 0;
        int MAX_INT = 2147483647, MIN_INT = -2147483648;
        for (char c : str)
        {
            if (num > MAX_INT / 10 || (num == MAX_INT / 10 && c - '0' > 7))
            {
                if (sign == 1)
                    return MAX_INT;
                else
                    return MIN_INT;
            }
            num *= 10;
            num += c - '0';
        }
        return sign * num;
    }
};