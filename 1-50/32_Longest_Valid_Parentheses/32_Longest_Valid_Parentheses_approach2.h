/**
 * Approach 2: Using Dynamic Programming
 * 
 * The difference between this one and the original one is that we don't use a stack here.
**/

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        vector<int> leftlegth(s.size(), 0);
        int maxlen = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    leftlegth[i] = 2;
                    if (i - 2 > 0)
                        leftlegth[i] += leftlegth[i - 2];
                }
                else
                {
                    if (i - leftlegth[i - 1] - 1 >= 0 && s[i - leftlegth[i - 1] - 1] == '(')
                    {
                        leftlegth[i] = leftlegth[i - 1] + 2;
                        if (i - leftlegth[i - 1] - 2 > 0)
                            leftlegth[i] += leftlegth[i - leftlegth[i - 1] - 2];
                    }
                }
                if (leftlegth[i] > maxlen)
                    maxlen = leftlegth[i];
            }
        }
        return maxlen;
    }
};