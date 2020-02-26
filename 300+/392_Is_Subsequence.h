#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;
        int index = 0;
        for(int j = 0; j < t.size(); j++){
            if(s[index] == t[j]){
                index++;
                if(index == s.size())
                    return true;
            }
        }
        return false;
    }
};