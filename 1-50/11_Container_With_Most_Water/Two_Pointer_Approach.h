#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0, current_area = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            if (height[j] < height[i])
            {
                current_area = (j - i) * height[j];
                max_area = max(current_area, max_area);
                --j;
            }
            else
            {
                current_area = (j - i) * height[i];
                max_area = max(current_area, max_area);
                ++i;
            }
        }
        return max_area;
    }
};