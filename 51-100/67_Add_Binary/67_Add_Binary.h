#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        bool digita, digitb, digitr;
        bool left = false;
        string ret;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0)
        {
            digita = i >= 0 && a[i] == '1';
            digitb = j >= 0 && b[j] == '1';
            digitr = (digita ^ digitb) ^ left;
            if (digitr)
                ret.push_back('1');
            else
                ret.push_back('0');
            if (left)
                left = digita || digitb;
            else
                left = digita && digitb;
            i--, j--;
        }
        if (left)
            ret.push_back('1');
        i = 0, j = ret.size() - 1;
        while (i < j)
        {
            char temp = ret[i];
            ret[i] = ret[j];
            ret[j] = temp;
            i++, j--;
        }
        return ret;
    }
};