#include <iostream>
#include "239_Sliding_Window_Maximum.h"

int main() {
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, k);

    cout << '[';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}