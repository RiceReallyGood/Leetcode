#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));
        vector<int> iStack;

        int col = 0;
        int Determined = 0;
        while (!iStack.empty() || col < n)
        {
            if (col < n)
            {
                if (IsValid(iStack, col))
                {
                    iStack.push_back(col);
                    board[Determined][col] = 'Q';
                    Determined++;
                    if (Determined == n)
                    {
                        ret.push_back(board);
                        board[n - 1][iStack.back()] = '.';
                        iStack.pop_back();
                        Determined--;
                        col = n;
                    }
                    else
                        col = 0;
                }
                else
                    col++;
            }
            else
            {
                col = iStack.back();
                iStack.pop_back();
                Determined--;
                board[Determined][col] = '.';
                col++;
            }
        }
        return ret;
    }

    bool IsValid(vector<int> &locations, int col)
    {
        int row = locations.size();
        for (int i = 0; i < locations.size(); i++)
        {
            if (locations[i] == col)
                return false;
            if (i + locations[i] == row + col)
                return false;
            if (i - locations[i] == row - col)
                return false;
        }
        return true;
    }
};