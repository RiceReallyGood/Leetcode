#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int tCount[128] {};
        for (char c : t) {
            ++tCount[c];
        }
        int setSize = 0;
        for (int i = 0; i < 128; i++) {
            if (tCount[i]) {
                ++setSize;
            }
        }

        int start = 0, len = s.length() + 1;
        int sCount[128] {};
        for (int i = 0, j = 0; i < s.length(); i++) {
            ++sCount[s[i]];
            if (sCount[s[i]] == tCount[s[i]]) {
                --setSize;
            }

            if (setSize == 0) {
                while (setSize == 0 && j <= i) {
                    if (sCount[s[j]] == tCount[s[j]]) {
                        ++setSize;
                    }
                    --sCount[s[j]];
                    ++j;
                }

                if (i - j + 2 < len) {
                    start = j - 1;
                    len = i - j + 2;
                }
            }
        }

        return len == s.length() + 1 ? "" : s.substr(start, len);
    }
};