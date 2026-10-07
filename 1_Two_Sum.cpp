#include <iostream>
#include "1_Two_Sum.h"

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> res = s.twoSum(nums, 9);
    cout << res[0] << " " << res[1] << endl;
}