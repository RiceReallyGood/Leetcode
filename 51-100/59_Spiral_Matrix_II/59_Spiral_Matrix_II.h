#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        bool horizontal = true;
        int hori_steps = n, vert_steps = n;
        int hori_dir = 1, vert_dir = 1;
        int row = 0, col = -1;
        int num = 1;
        while (true)
        {
            if (horizontal)
            {
                if (hori_steps == 0)
                    break;
                for (int i = 0; i < hori_steps; i++)
                {
                    col += hori_dir;
                    matrix[row][col] = num;
                    num++;
                }
                vert_steps--;
                hori_dir = -hori_dir;
                horizontal = false;
            }
            else
            {
                if (vert_steps == 0)
                    break;
                for (int i = 0; i < vert_steps; i++)
                {
                    row += vert_dir;
                    matrix[row][col] = num;
                    num++;
                }
                hori_steps--;
                vert_dir = -vert_dir;
                horizontal = true;
            }
        }
        return matrix;
    }
};