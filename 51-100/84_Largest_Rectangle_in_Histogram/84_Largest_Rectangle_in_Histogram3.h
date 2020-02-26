#include <vector>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        vector<int> istack;
        istack.push_back(-1);
        int sz = heights.size();
        for (int i = 0; i < sz; i++)
        {
            while (istack.back() != -1 && heights[istack.back()] >= heights[i])
            {
                int h = heights[istack.back()];
                istack.pop_back();
                if (h > heights[i])
                    maxarea = max(maxarea, h * (i - istack.back() - 1));
            }
            istack.push_back(i);
        }
        while (istack.back() != -1)
        {
            int h = heights[istack.back()];
            istack.pop_back();
            maxarea = max(maxarea, (sz - istack.back() - 1) * h);
        }
        return maxarea;
    }
};