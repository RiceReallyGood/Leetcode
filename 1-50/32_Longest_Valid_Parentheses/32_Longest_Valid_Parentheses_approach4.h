/**
 * Approach 4: Without extra space
 * Algorithm:
 * In this approach, we make use of two counters leftleft and rightright.
 * First, we start traversing the string from the left towards the right and for every ‘(’ encountered,
 * we increment the leftleft counter and for every ')' encountered, we increment the rightright counter.
 * Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string 
 * and keep track of maximum length substring found so far. If rightright becomes greater than leftleft
 * we reset leftleft and rightright to 0.
 **/

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0;
        int leftbound = -1;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                left++;
            else
            {
                right++;
                if (right > left)
                {
                    left = right = 0;
                    leftbound = i;
                }
                if (right == left)
                    maxlen = max(maxlen, left + right);
            }
        }

        left = right = 0;
        for (int i = s.size() - 1; i > leftbound; i--)
        {
            if (s[i] == ')')
                right++;
            else
            {
                left++;
                if (left > right)
                    left = right = 0;
                if (left == right)
                    maxlen = max(maxlen, left + right);
            }
        }

        return maxlen;
    }
};