#include <iostream>
#include "75_Sort_Colors.h"

int main() {
    vector<int> nums {2,0,2,1,1,0};
    Solution().sortColors(nums);
    cout << '[';
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}