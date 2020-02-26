#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret;
        if (strs.empty())
            return ret;
        for (int i = 0;; ++i)
        {
            for (int j = 0; j < strs.size(); ++j)
            {
                if (strs[j].size() == i)
                    return ret;
                if (strs[j][i] != strs[0][i])
                    return ret;
            }
            ret.push_back(strs[0][i]);
        }
        return ret;
    }
};