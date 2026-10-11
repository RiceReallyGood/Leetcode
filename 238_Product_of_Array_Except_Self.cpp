#include <iostream>
#include "238_Product_of_Array_Except_Self.h"

int main() {
    vector<int> nums {-1,1,0,-3,3};
    Solution s;
    
    vector<int> res = s.productExceptSelf(nums);
    cout << '[';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}