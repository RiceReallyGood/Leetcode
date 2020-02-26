#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        for (int width = 1; width < height.size(); ++width)
        {
            for (int i = 0; i + width < height.size(); ++i)
            {
                int current_area = width * min(height[i], height[i + width]);
                if (current_area > max_area)
                    max_area = current_area;
            }
        }
        return max_area;
    }
};