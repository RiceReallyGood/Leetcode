#include <iostream>
#include "42_Trapping_Rain_Water.h"

int main() {
    vector<int> heights {4,2,0,3,2,5};
    Solution s;
    cout << s.trap(heights) << endl;
}