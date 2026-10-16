#include <iostream>
#include "31_Next_Permutation.h"

int main() {
    vector<int> nums {1,5,1};
    Solution().nextPermutation(nums);
    cout << '[';
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}