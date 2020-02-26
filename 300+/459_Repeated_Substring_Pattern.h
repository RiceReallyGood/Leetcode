#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int pieces = 2; pieces <= n; pieces++){
            if(n % pieces != 0) continue;
            int len = n / pieces;
            int displace = 0;
            for(; displace < len; displace++){
                int i = 1;
                for(; i < pieces; i++){
                    if(s[i * len + displace] != s[displace])
                        break;
                }
                if(i < pieces)
                    break;
            }
            if(displace == len)
                return true;
        }
        return false;
    }
};