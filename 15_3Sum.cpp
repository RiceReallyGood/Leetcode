#include <iostream>
#include "15_3Sum.h"

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    
    cout << '[';
    for (int i = 0; i < res.size(); i++) {
        const auto &triplet = res[i];
        cout << '[' << triplet[0] << ',' << triplet[1] << ',' << triplet[2] << ']';
        if (i != res.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}