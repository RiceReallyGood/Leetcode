#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));
        if (n == 0)
            return ret;
        if (n == 1)
            return vector<vector<string>>(1, vector<string>(1, "Q"));
        unordered_set<int> valid_cols, valid_sums, valid_diffs;
        for (int i = 0; i < n; i++)
            valid_cols.insert(i);
        for (int i = 0; i < 2 * n - 1; i++)
            valid_sums.insert(i);
        for (int i = -n + 1; i < n; i++)
            valid_diffs.insert(i);

        vector<int> ColStack;
        int Determined = 0;
        int col = 0;
        int sum, diff;
        while (!ColStack.empty() || col < n)
        {
            if (col < n)
            {
                sum = Determined + col;
                diff = Determined - col;
                if (valid_cols.find(col) != valid_cols.end() && valid_sums.find(sum) != valid_sums.end() && valid_diffs.find(diff) != valid_diffs.end())
                {
                    ColStack.push_back(col);
                    board[Determined][col] = 'Q';
                    valid_cols.erase(col);
                    valid_sums.erase(sum);
                    valid_diffs.erase(diff);
                    Determined++;
                    col = 0;
                }
                else
                    col++;
            }
            else
            {
                Determined--;
                col = ColStack.back();
                if (col < 0)
                    break;
                ColStack.pop_back();
                board[Determined][col] = '.';
                sum = Determined + col;
                diff = Determined - col;
                valid_cols.insert(col);
                valid_sums.insert(sum);
                valid_diffs.insert(diff);
                col++;
            }
            if (Determined == n)
            {
                ret.push_back(board);
                for (int i = 0; i < 2; i++)
                {
                    Determined--;
                    col = ColStack.back();
                    ColStack.pop_back();
                    board[Determined][col] = '.';
                    sum = Determined + col;
                    diff = Determined - col;
                    valid_cols.insert(col);
                    valid_sums.insert(sum);
                    valid_diffs.insert(diff);
                }
                col++;
            }
        }
        return ret;
    }
};