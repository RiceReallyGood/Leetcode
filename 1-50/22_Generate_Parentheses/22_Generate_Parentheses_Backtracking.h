/**
 * Algorithm:
 * We can start an opening bracket if we still have one (of n) left to place.
 * And we can start a closing bracket if it would not exceed the number of opening brackets.
**/

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        backtrack(ret, "", 0, 0, n);
        return ret;
    }

    void backtrack(vector<string> &ret, string s, int open, int close, int max)
    {
        if (s.size() == max * 2)
        {
            ret.push_back(s);
            return;
        }

        if (open < max)
            backtrack(ret, s + '(', open + 1, close, max);
        if (open > close)
            backtrack(ret, s + ')', open, close + 1, max);
    }
};