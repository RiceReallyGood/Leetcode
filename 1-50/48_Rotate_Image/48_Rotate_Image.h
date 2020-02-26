#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int n = 0; n < matrix.size() / 2; n++)
            RotateFrame(matrix, n);
    }
    void RotateFrame(vector<vector<int>> &matrix, int n)
    {
        int n_mirror = matrix.size() - 1 - n;
        for (int j = n; j < n_mirror; j++)
        {
            int j_mirror = matrix.size() - 1 - j;
            int temp = matrix[n][j];
            matrix[n][j] = matrix[j_mirror][n];
            matrix[j_mirror][n] = matrix[n_mirror][j_mirror];
            matrix[n_mirror][j_mirror] = matrix[j][n_mirror];
            matrix[j][n_mirror] = temp;
        }
    }
};