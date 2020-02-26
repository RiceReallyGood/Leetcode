#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int vol = 0;
        int h;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                h = height[left];
                left++;
                while (height[left] <= h)
                {
                    vol += h - height[left];
                    left++;
                }
            }
            else
            {
                h = height[right];
                right--;
                while (height[right] < h)
                {
                    vol += h - height[right];
                    right--;
                }
            }
        }
        return vol;
    }
};