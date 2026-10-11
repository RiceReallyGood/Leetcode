#include <iostream>
#include "56_Merge_Intervals.h"

int main() {
    vector<vector<int>> intervals {{1,3},{2,6},{8,10},{15,18}};
    Solution s;

    vector<vector<int>> res = s.merge(intervals);

    cout << '[';
    for (int i = 0; i < intervals.size(); i++) {
        cout << '[' << intervals[i][0] << ',' << intervals[i][1] << ']';
        if (i != intervals.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}