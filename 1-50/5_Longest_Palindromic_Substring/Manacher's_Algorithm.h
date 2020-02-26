#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        //preProcess
        string new_s;
        if (s.size() == 0)
            new_s = "^$";
        else
        {
            new_s = "^";
            for (char c : s)
            {
                new_s.push_back('#');
                new_s.push_back(c);
            }
            new_s += "#$";
        }

        int sz = new_s.size();
        int *p = new int[sz];
        int center = 0, rightbound = 0;
        p[0] = 0;
        p[1] = 0;
        int maxlen = 0, start_point = 0;
        for (int i = 2; i < sz - maxlen - 1; ++i)
        {
            if (i > rightbound)
            {
                center = i;
                p[i] = 0;
                while (new_s[i - p[i] - 1] == new_s[i + p[i] + 1])
                    ++p[i];
                rightbound = i + p[i];
                if (p[i] > maxlen)
                {
                    maxlen = p[i];
                    //start_point = (i - p[i] + 1) / 2 - 1;
                    start_point = (i - p[i]) / 2;
                }
            }
            int iMirror = 2 * center - i;
            if (i + p[iMirror] < rightbound)
                p[i] = p[iMirror];
            else if (i + p[iMirror] > rightbound)
                p[i] = rightbound - i;
            else
            {
                center = i;
                p[i] = p[iMirror];
                while (new_s[i - p[i] - 1] == new_s[i + p[i] + 1])
                    ++p[i];
                rightbound = i + p[i];
                if (p[i] > maxlen)
                {
                    maxlen = p[i];
                    //start_point = (i - p[i] + 1) / 2 - 1;
                    start_point = (i - p[i]) / 2;
                }
            }
        }
        return s.substr(start_point, maxlen);
    }
};