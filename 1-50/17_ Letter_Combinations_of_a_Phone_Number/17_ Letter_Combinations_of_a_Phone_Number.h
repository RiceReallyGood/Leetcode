#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<int> orders(digits.size(), 0);
        string s;
        vector<string> ret;
        if (digits.size() == 0)
            return ret;
        for (int i = 0; i < digits.size(); i++)
            s += Digit2Letter[digits[i]][orders[i]];

        ret.push_back(s);

        while (true)
        {
            int i;
            for (i = orders.size() - 1; i >= 0; i--)
            {
                if (orders[i] < Digit2Letter[digits[i]].size() - 1)
                {
                    orders[i]++;
                    s[i] = Digit2Letter[digits[i]][orders[i]];
                    break;
                }
                else
                {
                    orders[i] = 0;
                    s[i] = Digit2Letter[digits[i]][orders[i]];
                }
            }
            if (i < 0)
                break;
            ret.push_back(s);
        }
        return ret;
    }

    map<char, string> Digit2Letter = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};