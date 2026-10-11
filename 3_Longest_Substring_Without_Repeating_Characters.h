#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charCount[256] = {};
        int res = 0;

        for (int i = 0, j = 0; i < s.length(); i++) {
            if (charCount[s[i]]) {
                while (s[j] != s[i]) {
                    charCount[s[j]] = 0;
                    ++j;
                }
                ++j;
                continue;
            }

            charCount[s[i]] = 1;
            res = max(res, i - j + 1);
        }

        return res;
    }
};