#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int sz = s.size();
        unordered_set<string> VaildChars = {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
            "21", "22", "23", "24", "25", "26"};

        vector<int> numDecodingsBefore;
        numDecodingsBefore.resize(sz + 1);
        numDecodingsBefore[0] = 1;
        numDecodingsBefore[1] = VaildChars.find(s.substr(0, 1)) == VaildChars.end() ? 0 : 1;
        if (sz == 1)
            return numDecodingsBefore[1];
        for (int i = 2; i <= sz; i++)
        {
            if (VaildChars.find(s.substr(i - 1, 1)) == VaildChars.end())
            {
                if (VaildChars.find(s.substr(i - 2, 2)) == VaildChars.end())
                    numDecodingsBefore[i] = 0;
                else
                    numDecodingsBefore[i] = numDecodingsBefore[i - 2];
            }
            else
            {
                if (VaildChars.find(s.substr(i - 2, 2)) == VaildChars.end())

                    numDecodingsBefore[i] = numDecodingsBefore[i - 1];
                else
                    numDecodingsBefore[i] = numDecodingsBefore[i - 1] + numDecodingsBefore[i - 2];
            }
        }
        return numDecodingsBefore[sz];
    }
};