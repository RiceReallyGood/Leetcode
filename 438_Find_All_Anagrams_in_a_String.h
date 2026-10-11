#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.length() > s.length()) {
            return res;
        }

        int charCount[26] = {};
        int nonZeros = 0;
        // initialize
        for (int i = 0; i < p.length(); i++) {
            ++charCount[p[i] - 'a'];
        }

        for (int i = 0; i < p.length(); i++) {
            --charCount[s[i] - 'a'];
        }

        for (int i = 0; i < 26; i++) {
            if (charCount[i]) {
                ++nonZeros;
            }
        }

        if (nonZeros == 0) {
            res.push_back(0);
        }

        for (int i = p.length(); i < s.length(); i++) {
            const int decCount = --charCount[s[i] - 'a'];
            if (decCount == 0) {
                --nonZeros;
            } else if (decCount == -1) {
                ++nonZeros;
            }

            const int incCount = ++charCount[s[i - p.length()] - 'a'];
            if (incCount == 0) {
                --nonZeros;
            } else if (incCount == 1) {
                ++nonZeros;
            }

            if (nonZeros == 0) {
                res.push_back(i - p.length() + 1);
            }
        }

        return res;
    }
};