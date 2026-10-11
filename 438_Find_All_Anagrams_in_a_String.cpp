#include <iostream>
#include "438_Find_All_Anagrams_in_a_String.h"

int main() {
    string str = "bpaa";
    string p = "aa";
    Solution s;
    vector<int> res = s.findAnagrams(str, p);
    cout << '[';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}