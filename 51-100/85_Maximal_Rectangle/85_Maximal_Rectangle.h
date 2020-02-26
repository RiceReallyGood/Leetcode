#include <vector>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxarea = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    ++heights[j];
            }
            maxarea = max(maxarea, largestRectangleArea(heights));
        }
        return maxarea;
    }

private:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        int sz = heights.size();
        vector<int> indexstack;
        indexstack.push_back(-1);
        for (int i = 0; i < sz; i++)
        {
            while (indexstack.back() != -1 && heights[indexstack.back()] >= heights[i])
            {
                int h = heights[indexstack.back()];
                indexstack.pop_back();
                if (h > heights[i])
                    maxarea = max(maxarea, h * (i - indexstack.back() - 1));
            }
            indexstack.push_back(i);
        }

        while (indexstack.back() != -1)
        {
            int h = heights[indexstack.back()];
            indexstack.pop_back();
            maxarea = max(maxarea, h * (sz - indexstack.back() - 1));
        }
        return maxarea;
    }
};