#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = (int)height.size() - 1;

        int res = 0;
        while (i < j) {
            int area = 0;
            if (height[i] < height[j]) {
                area = height[i] * (j - i);
                ++i;
            } else if (height[i] > height[j]) {
                area = height[j] * (j - i);
                --j;
            } else {
                area = height[i] * (j - i);
                ++i;
                --j;
            }
            res = max(res, area);
        }
        return res;
    }
};