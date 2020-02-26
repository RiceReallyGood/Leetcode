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
        vector<string> lines;
        lines.resize(numRows);
        int line = 0, direction = 1;
        int maxline = numRows - 1;
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            lines[line].push_back(s[i]);
            if (line == 0)
                direction = 1;
            else if (line == maxline)
                direction = -1;
            line += direction;
        }
        s = "";
        for (int i = 0; i < numRows; ++i)
        {
            s += lines[i];
        }
        return s;
    }
};