#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        for (int i = 0; i < height.size() - 1; ++i)
        {
            for (int j = i + 1; j < height.size(); ++j)
            {
                int current_area = (j - i) * min(height[i], height[j]);
                if (current_area > max_area)
                    max_area = current_area;
            }
        }
        return max_area;
    }
};