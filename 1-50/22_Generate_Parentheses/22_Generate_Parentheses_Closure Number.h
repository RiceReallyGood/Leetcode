/**
 * For each closure number c, we know the starting and ending brackets must be at index 0 and 2*c + 1.
 * Then, the 2*c elements between must be a valid sequence, plus the rest of the elements must be a valid sequence.
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
        if (n == 0)
        {
            ret.push_back("");
        }
        else
        {
            for (int c = 0; c < n; c++)
            {
                for (string left : generateParenthesis(c))
                    for (string right : generateParenthesis(n - 1 - c))
                        ret.push_back('(' + left + ')' + right);
            }
        }
        return ret;
    }
};