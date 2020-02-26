#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<unsigned long> vnum1, vnum2;

        while (!num1.empty())
        {
            if (num1.size() >= 9)
            {
                vnum1.push_back(stoul(num1.substr(num1.size() - 9, 9)));
                num1.resize(num1.size() - 9);
            }
            else
            {
                vnum1.push_back(stoul(num1));
                num1.clear();
            }
        }

        while (!num2.empty())
        {
            if (num2.size() >= 9)
            {
                vnum2.push_back(stoul(num2.substr(num2.size() - 9, 9)));
                num2.resize(num2.size() - 9);
            }
            else
            {
                vnum2.push_back(stoul(num2));
                num2.clear();
            }
        }

        unsigned long divisor = 1000000000UL;
        vector<unsigned long> prod(vnum1.size() + vnum2.size(), 0);
        for (int i = 0; i < vnum1.size(); i++)
        {
            for (int j = 0; j < vnum2.size(); j++)
            {
                prod[i + j] += vnum1[i] * vnum2[j];
                prod[i + j + 1] += prod[i + j] / divisor;
                prod[i + j] %= divisor;
            }
        }

        while (!prod.empty() && prod.back() == 0)
            prod.pop_back();
        if (prod.empty())
            prod.push_back(0);

        ostringstream out;
        auto iter = prod.rbegin();
        out << *iter++;
        while (iter != prod.rend())
            out << setfill('0') << setw(9) << *iter++;

        return out.str();
    }
};