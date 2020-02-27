#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for(char c : s)
            count[c]++;
        bool HasOdd = false;
        int ret = 0;
        for(int i = 0; i < 128; i++){
            if(count[i] & 1){
                HasOdd = true;
                ret += count[i] - 1;
            }
            else
                ret += count[i];
        }
        return HasOdd ? ret + 1 : ret;
    }
};