#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        vector<int> leftlegth(s.size(), 0);
        vector<int> iStack;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                iStack.push_back(i);
            else
            {
                if (!iStack.empty())
                {
                    int open = iStack.back();
                    iStack.pop_back();
                    leftlegth[i] = i - open + 1;
                    if (open > 0)
                        leftlegth[i] += leftlegth[open - 1];

                    if (leftlegth[i] > maxlen)
                        maxlen = leftlegth[i];
                }
            }
        }
        return maxlen;
    }
};