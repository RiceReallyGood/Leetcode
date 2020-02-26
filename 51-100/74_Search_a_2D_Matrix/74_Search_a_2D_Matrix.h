#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int elems = rows * cols;
        int left = 0, right = elems - 1;
        while (left < right)
        {
            int center = (right - left) / 2 + left;
            if (matrix[center / cols][center % cols] < target)
                left = center + 1;
            else
                right = center;
        }
        return matrix[left / cols][left % cols] == target;
    }
};