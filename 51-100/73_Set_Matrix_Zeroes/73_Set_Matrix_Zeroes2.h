#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool IsFirstColumZero = false;
        int m = matrix.size();
        if (m == 0)
            return;

        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                IsFirstColumZero = true;

            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 1; j < n; j++)
                matrix[0][j] = 0;

        if (IsFirstColumZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};