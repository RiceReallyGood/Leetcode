#include <iostream>
#include "49_Group_Anagrams.h"

int main() {
    vector<string> strs {"a"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    
    cout << '[';
    for (const auto &group : res) {
        cout << '[';
        for (int i = 0; i < group.size(); i++) {
            cout << '\"' << group[i] << '\"';
            if (i != group.size() - 1) {
                cout << ',';
            }
        }
        cout << ']';
    }
    cout << ']';
}