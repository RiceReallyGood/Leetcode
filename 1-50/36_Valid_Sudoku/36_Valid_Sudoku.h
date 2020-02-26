#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> all_nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        //check rows
        for (int row = 0; row < 9; row++)
        {
            unordered_set<char> nums_left = all_nums;
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;
                else
                {
                    if (nums_left.find(board[row][col]) != nums_left.end())
                        nums_left.erase(board[row][col]);
                    else
                        return false;
                }
            }
        }

        //check cols
        for (int col = 0; col < 9; col++)
        {
            unordered_set<char> nums_left = all_nums;
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] == '.')
                    continue;
                else
                {
                    if (nums_left.find(board[row][col]) != nums_left.end())
                        nums_left.erase(board[row][col]);
                    else
                        return false;
                }
            }
        }

        //check grids
        for (int grid_row = 0; grid_row < 3; grid_row++)
        {
            for (int grid_col = 0; grid_col < 3; grid_col++)
            {
                unordered_set<char> nums_left = all_nums;
                for (int row = grid_row * 3; row < (grid_row + 1) * 3; row++)
                {
                    for (int col = grid_col * 3; col < (grid_col + 1) * 3; col++)
                    {
                        if (board[row][col] == '.')
                            continue;
                        else
                        {
                            if (nums_left.find(board[row][col]) != nums_left.end())
                                nums_left.erase(board[row][col]);
                            else
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};