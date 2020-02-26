#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty())
            return string();
        string ret = "0";
        int lastindex[26] = {-1};
        bool used[26] = {false};
        for(int i = 0; i < s.length(); i++)
            lastindex[s[i] - 'a'] = i;
        for(int i = 0; i < s.length(); i++){
            if(used[s[i] - 'a']) continue;
            while(s[i] < ret.back() && lastindex[ret.back() - 'a'] > i){
                used[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret.push_back(s[i]);
            used[s[i] - 'a'] = true;
        }
        return ret.substr(1);
    }
};