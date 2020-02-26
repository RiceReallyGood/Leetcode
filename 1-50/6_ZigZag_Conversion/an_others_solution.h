#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int sz = s.size();
        string ret;
        ret.resize(sz);
        int steps[2] = {0};
        //first line
        steps[0] = 2 * numRows - 2;
        int index = 0;
        while (index < sz)
        {
            ret.push_back(s[index]);
            index += steps[0];
        }
        //lines in the middle
        for (int i = 1; i < numRows - 1; ++i)
        {
            index = i;
            steps[0] = numRows * 2 - 2 * i - 2;
            steps[1] = 2 * i;
            while (index < sz)
            {
                ret.push_back(s[index]);
                if ((index += steps[0]) >= sz)
                    break;
                ret.push_back(s[index]);
                index += steps[1];
            }
        }
        //the last line
        steps[0] = 2 * numRows - 2;
        index = numRows - 1;
        while (index < sz)
        {
            ret.push_back(s[index]);
            index += steps[0];
        }
        return ret;
    }
};