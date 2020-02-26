#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ret;
        int totalnum = s.length();
        if (totalnum < 4 || totalnum > 12)
            return ret;

        vector<int> parts;
        fill_left(parts, totalnum);
        if (IsValidIP(s, parts))
            ret.push_back(Parts2IP(s, parts));

        int leftnum = 0;
        while (true)
        {
            while (!parts.empty() && (parts.back() == 3 || leftnum - 1 < 4 - static_cast<int>(parts.size())))
            {
                leftnum += parts.back();
                parts.pop_back();
            }

            if (parts.empty())
                break;

            parts.back()++;
            leftnum--;
            fill_left(parts, leftnum);
            leftnum = 0;
            if (IsValidIP(s, parts))
                ret.push_back(Parts2IP(s, parts));
        }
        return ret;
    }

private:
    bool IsValidPart(const string &s)
    {
        if (s[0] == '0' && s.length() > 1)
            return false;
        return stoi(s) < 256;
    }

    bool IsValidIP(const string &s, const vector<int> &parts)
    {
        bool ret = true;
        int start = 0;
        for (int i = 0; i < 4; i++)
        {
            ret = ret && IsValidPart(s.substr(start, parts[i]));
            start += parts[i];
        }
        return ret;
    }

    void fill_left(vector<int> &parts, int leftnum)
    {
        int sz = parts.size();
        int maxfilled = (leftnum - (4 - sz)) / 2;
        parts.resize(4);

        for (int i = 0; i < 4 - sz; i++)
        {
            if (i < maxfilled)
                parts[3 - i] = 3;
            else if (i == maxfilled)
                parts[3 - i] = (leftnum - (4 - sz)) % 2 + 1;
            else
                parts[3 - i] = 1;
        }
    }

    string Parts2IP(const string &s, vector<int> &parts)
    {
        string ret = s.substr(0, parts[0]);
        int start = parts[0];
        for (int i = 1; i < 4; i++)
        {
            ret += ".";
            ret += s.substr(start, parts[i]);
            start += parts[i];
        }
        return ret;
    }
};