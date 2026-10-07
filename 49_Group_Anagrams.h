#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int nstr = strs.size();
        vector<int> isGrouped(nstr, 0);
        vector<vector<string>> res;

        for (int i = 0; i < nstr; i++) {
            if (isGrouped[i]) {
                continue;
            }

            res.push_back(vector<string>());
            res.back().push_back(strs[i]);
            isGrouped[i] = 1;

            vector<int> charCount(26, 0);
            int len = strs[i].length();
            for (char c : strs[i]) {
                ++charCount[c - 'a'];
            }

            for (int j = i + 1; j < nstr; j++) {
                if (isGrouped[j]) {
                    continue;
                }

                if (strs[j].length() != len) {
                    continue;
                }

                for (char c : strs[j]) {
                    --charCount[c - 'a'];
                }

                bool isAnagram = true;
                for (int k = 0; k < 26; k++) {
                    if (charCount[k] != 0) {
                        isAnagram = false;
                    }
                }

                if (isAnagram) {
                    isGrouped[j] = 1;
                    res.back().push_back(strs[j]);
                }

                for (char c : strs[j]) {
                    ++charCount[c - 'a'];
                }
            }
        }

        return res;
    }
};