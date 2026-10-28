#include <iostream>
#include "307_Range_Sum_Query-Mutable.h"

int main() {
    vector<int> nums {-28,-39,53,65,11,-56,-65,-39,-43,97};
    NumArray a(nums);
    cout << a.sumRange(5, 6);
}