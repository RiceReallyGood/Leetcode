#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        if (matrix.empty())
            return ret;
        bool horizontal = true;
        int hori_step = matrix[0].size();
        int verti_step = matrix.size();
        int row = 0, col = -1;
        int hori_dir = 1, verti_dir = 1;
        while (true)
        {
            if (horizontal)
            {
                if (hori_step == 0)
                    break;
                for (int i = 0; i < hori_step; i++)
                {
                    col += hori_dir;
                    ret.push_back(matrix[row][col]);
                }
                hori_dir = -hori_dir;
                verti_step--;
                horizontal = false;
            }
            else
            {
                if (verti_step == 0)
                    break;
                for (int i = 0; i < verti_step; i++)
                {
                    row += verti_dir;
                    ret.push_back(matrix[row][col]);
                }
                verti_dir = -verti_dir;
                hori_step--;
                horizontal = true;
            }
        }
        return ret;
    }
};