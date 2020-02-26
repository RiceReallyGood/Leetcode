/**
 * 前序遍历一棵树
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
        string s, rets;
        vector<int> iStack;
        int left = 0;
        while (true)
        {
            while (left < n)
            {
                s += '(';
                left++;
                if (left < n)
                    iStack.push_back(s.size() + 1);
            }
            rets = s;
            rets.resize(2 * n, ')');
            ret.push_back(rets);

            if (iStack.empty())
                break;

            int change = iStack.back();
            iStack.pop_back();
            while (s.size() >= change)
            {
                if (s.back() == '(')
                    left--;
                s.pop_back();
            }
            s += ')';
            if (s.size() - left < left)
                iStack.push_back(s.size() + 1);
        }
        return ret;
    }
};