#include <iostream>
#include "283_Move_Zeroes.h"

int main() {
    vector<int> nums {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ',';
        }
    }
    cout << endl;
}