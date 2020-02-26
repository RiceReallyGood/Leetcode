#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> SortedStrings;
        for (string s : strs)
        {
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            SortedStrings[s_copy].push_back(s);
        }
        for (auto pair : SortedStrings)
            ret.push_back(pair.second);
        return ret;
    }
};