#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for(int i = 0; i < s.length(); i++)
            n = n * 26 - 'A' + s[i]  + 1;
        return n;
    }
};