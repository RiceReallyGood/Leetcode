#include <string>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string ret;
        int sz = path.size();
        int Slash1 = 0, Slash2;
        while (Slash1 < sz)
        {
            Slash2 = Slash1 + 1;
            while (Slash2 < sz && path[Slash2] != '/')
                Slash2++;
            string dir = path.substr(Slash1 + 1, Slash2 - Slash1 - 1);
            Slash1 = Slash2;
            if (dir == "." || dir.empty())
                continue;
            if (dir == "..")
            {
                if (ret.empty())
                    continue;
                while (ret.back() != '/')
                    ret.pop_back();
                ret.pop_back();
            }
            else
                ret += "/" + dir;
        }
        if (ret.empty())
            return "/";
        else
            return ret;
    }
};