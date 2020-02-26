#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int appeartimes[26] = {0};
        for(auto c : s)
            ++appeartimes[c - 'a'];
        for(auto c : t)
            --appeartimes[c - 'a'];
        for(int i = 0; i< 26; i++)
            if(appeartimes[i] != 0)
                return false;
        return true;
    }
};