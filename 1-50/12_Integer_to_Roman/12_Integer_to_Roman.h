#include <string>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        string str;
        int digit = num / 1000;
        num %= 1000;
        for (int i = 0; i < digit; ++i)
            str += "M";

        digit = num / 500;
        num %= 500;
        if (num >= 400)
        {
            if (digit == 1)
                str += "CM";
            else
                str += "CD";
            num -= 400;
        }
        else
        {
            if (digit == 1)
                str += "D";
        }

        digit = num / 100;
        num %= 100;
        for (int i = 0; i < digit; ++i)
            str += "C";

        digit = num / 50;
        num %= 50;
        if (num >= 40)
        {
            if (digit == 1)
                str += "XC";
            else
                str += "XL";
            num -= 40;
        }
        else
        {
            if (digit == 1)
                str += "L";
        }

        digit = num / 10;
        num %= 10;
        for (int i = 0; i < digit; ++i)
            str += "X";

        digit = num / 5;
        num %= 5;
        if (num == 4)
        {
            if (digit == 1)
                str += "IX";
            else
                str += "IV";
            num -= 4;
        }
        else
        {
            if (digit == 1)
                str += "V";
        }

        for (int i = 0; i < num; ++i)
            str += "I";

        return str;
    }
};