#include <iostream>
#include "560_Subarray_Sum_Equals_K.h"

int main() {
    vector<int> nums {1,2,3};
    int k = 3;
    Solution s;
    cout << s.subarraySum(nums, k) << endl;
}