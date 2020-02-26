#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    class cmp{
    public:
        bool operator()(string &s1, string &s2){
            return s1 + s2 < s2 + s1;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int n : nums)
            snums.push_back(to_string(n));
        
        sort(snums.begin(), snums.end(), cmp());
        if(snums.back() == "0")
            return "0";
        string ret;
        for(int i = snums.size() - 1; i >= 0; i--)
            ret += snums[i];
        return ret;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int n : nums)
            snums.push_back(to_string(n));
        
        sort(snums.begin(), snums.end(), [](const string& s1, const string& s2) { return s1 + s2 > s2 + s1; });
        if(snums[0]== "0")
            return "0";
        string ret;
        for(string n : snums)
            ret += n;
        return ret;
    }
};