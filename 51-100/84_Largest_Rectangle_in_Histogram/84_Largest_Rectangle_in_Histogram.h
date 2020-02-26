#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        int sz = heights.size();
        int minh;
        for (int i = 0; i < sz; i++)
        {
            minh = heights[i];
            maxarea = max(maxarea, heights[i]);
            for (int j = i + 1; j < sz; j++)
            {
                minh = min(heights[j], minh);
                maxarea = max(maxarea, (j - i + 1) * minh);
            }
        }
        return maxarea;
    }
};

//Time Limit Exceeded