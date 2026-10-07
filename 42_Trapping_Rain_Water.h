#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int h = 0;
        int res = 0;

        int l = 0, r = height.size() - 1;
        while (l < r) {
            while (l < r && height[l] <= h) {
                res += h - height[l++];
            }

            while (l < r && height[r] <= h) {
                res += h - height[r--];
            }

            h = min(height[l], height[r]);
        }
        return res;
    }
};