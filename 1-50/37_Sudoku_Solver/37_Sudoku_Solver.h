#include <vector>
#include <set>
using namespace std;

struct Node
{
    int row;
    int col;
    set<char>::iterator it;
    vector<pair<int, int>> Affected;
};

class Solution
{
  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        set<char> all_nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<vector<set<char>>> possible_nums_set(9, vector<set<char>>(9, set<char>()));
        vector<vector<bool>> filled(9, vector<bool>(9, false));
        int Determined = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    set<char> nums_left = all_nums;
                    //travel through the row
                    for (int k = 0; k < 9; k++)
                    {
                        if (board[i][k] == '.')
                            continue;
                        nums_left.erase(board[i][k]);
                    }
                    //travel through the col
                    for (int k = 0; k < 9; k++)
                    {
                        if (board[k][j] == '.')
                            continue;
                        nums_left.erase(board[k][j]);
                    }
                    //travel through the  grid
                    for (int k = (i / 3) * 3; k < (i / 3 + 1) * 3; k++)
                    {
                        for (int l = (j / 3) * 3; l < (j / 3 + 1) * 3; l++)
                        {
                            if (board[k][l] == '.')
                                continue;
                            nums_left.erase(board[k][l]);
                        }
                    }
                    possible_nums_set[i][j] = nums_left;
                }
                else
                {
                    filled[i][j] = true;
                    Determined++;
                }
            }
        }

        vector<Node> TriedStack;
        while (Determined < 81)
        {
            int row = 0, col = 0;
            int MinToTry = 9;
            set<char>::iterator it;
            for (int i = 0; i < 9; i++)
            {
                int j = 0;
                for (; j < 9; j++)
                {
                    if (filled[i][j])
                        continue;
                    if (possible_nums_set[i][j].empty())
                    {
                        Node poped;
                        do
                        {
                            poped = TriedStack.back();
                            TriedStack.pop_back();
                            poped.it++;
                            char c = board[poped.row][poped.col];
                            board[poped.row][poped.col] = '.';
                            filled[poped.row][poped.col] = false;
                            Determined--;
                            for (auto Index : poped.Affected)
                            {
                                possible_nums_set[Index.first][Index.second].insert(c);
                            }

                        } while (poped.it == possible_nums_set[poped.row][poped.col].end());
                        row = poped.row;
                        col = poped.col;
                        it = poped.it;
                        break;
                    }
                    if (possible_nums_set[i][j].size() < MinToTry)
                    {
                        MinToTry = possible_nums_set[i][j].size();
                        row = i;
                        col = j;
                        it = possible_nums_set[i][j].begin();
                    }
                }
                if (j != 9)
                    break;
            }

            Node topush;
            topush.row = row;
            topush.col = col;
            topush.it = it;
            board[row][col] = *it;
            filled[row][col] = true;
            Determined++;
            //travel through the row
            for (int j = 0; j < 9; j++)
            {
                if (filled[row][j])
                    continue;
                if (possible_nums_set[row][j].find(*it) != possible_nums_set[row][j].end())
                {
                    topush.Affected.push_back(make_pair(row, j));
                    possible_nums_set[row][j].erase(*it);
                }
            }
            //travel through the col
            for (int i = 0; i < 9; i++)
            {
                if (filled[i][col])
                    continue;
                if (possible_nums_set[i][col].find(*it) != possible_nums_set[i][col].end())
                {
                    topush.Affected.push_back(make_pair(i, col));
                    possible_nums_set[i][col].erase(*it);
                }
            }
            //travel through the  grid
            for (int i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++)
            {
                for (int j = (col / 3) * 3; j < (col / 3 + 1) * 3; j++)
                {
                    if (filled[i][j])
                        continue;
                    if (possible_nums_set[i][j].find(*it) != possible_nums_set[i][j].end())
                    {
                        topush.Affected.push_back(make_pair(i, j));
                        possible_nums_set[i][j].erase(*it);
                    }
                }
            }

            TriedStack.push_back(topush);
        }
    }
};