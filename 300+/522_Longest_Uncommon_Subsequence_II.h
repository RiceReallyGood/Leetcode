#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ret = -1;
        for(int i = 0; i < strs.size(); i++){
            int j = 0;
            for(; j < strs.size(); j++){
                if(j == i) continue;
                if(issubsequence(strs[j], strs[i]))
                    break;
            }
            if(j == strs.size()) ret = max(ret, int(strs[i].length()));
        }
        return ret;
    }

private:
    bool issubsequence(const string &s1, const string& s2){
        if(s1.length() < s2.length()) return false;
        int i = 0, j = 0;
        for(; i < s1.length(); i++){
            if(s1[i] == s2[j]){
                if(++j == s2.length())
                    break;
            }
        }
        return j == s2.length();
    }
};