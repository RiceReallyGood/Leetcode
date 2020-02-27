#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Binomial.h"
#include <unordered_set>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int N = height.size();
        vector<int> leftmax(N), rightmax(N);
        leftmax[0] = height[0];
        rightmax[N - 1] = height[N -1];
        for(int i = 1; i < N; i++)
            leftmax[i] = max(leftmax[i - 1], height[i]);
        for(int i = N - 2; i >= 0; i--)
            rightmax[i] = max(rightmax[i + 1], height[i]);
        int ret = 0;
        for(int i = 0; i < N; i++)
            ret += min(leftmax[i], rightmax[i]) - height[i];
        return ret;
    }
};