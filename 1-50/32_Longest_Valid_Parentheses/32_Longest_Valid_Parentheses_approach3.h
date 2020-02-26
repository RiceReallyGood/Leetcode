/**
 * Approach 3: Using Stack
**/

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        vector<int> iStack;
        iStack.push_back(-1);
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                iStack.push_back(i);
            else
            {
                iStack.pop_back();
                if (iStack.empty())
                    iStack.push_back(i);
                else
                    maxlen = max(maxlen, i - iStack.back());
            }
        }
        return maxlen;
    }
};