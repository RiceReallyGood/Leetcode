#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if (obstacleGrid[rows - 1][cols - 1] == 1)
            return 0;
        vector<vector<long>> board(rows, vector<long>(cols, 0));
        board[rows - 1][cols - 1] = 1;

        for (int j = cols - 2; j >= 0; j--)
        {
            if (obstacleGrid[rows - 1][j] == 1)
                board[rows - 1][j] = 0;
            else
                board[rows - 1][j] = board[rows - 1][j + 1];
        }

        for (int i = rows - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][cols - 1] == 1)
                board[i][cols - 1] = 0;
            else
                board[i][cols - 1] = board[i + 1][cols - 1];
        }

        for (int i = rows - 2; i >= 0; i--)
        {
            for (int j = cols - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == 1)
                    board[i][j] = 0;
                else
                    board[i][j] = board[i + 1][j] + board[i][j + 1];
            }
        }

        return board[0][0];
    }
};