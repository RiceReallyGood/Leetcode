#include <iostream>
#include "189_Rotate_Array.h"

int main() {
    vector<int> nums {1,2,3,4,5,6,7};
    int k = 3;
    Solution s;

    s.rotate(nums, k);

    cout << '[';
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}