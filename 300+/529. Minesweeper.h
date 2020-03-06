#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> revealed(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] != 'M' && board[i][j] != 'E')
                    revealed[i][j] = true;
        reveal(board, revealed, make_pair(click[0], click[1]));

        return board;
    }

private:
    void reveal(vector<vector<char>>& board, vector<vector<bool>>& revealed, const pair<int, int>& index){
        if(revealed[index.first][index.second]) return;
        if(board[index.first][index.second] == 'M'){
            board[index.first][index.second] = 'X';
            return;
        }
        revealed[index.first][index.second] = true;
        vector<pair<int, int>> unrevealedneighbours;
        int neighbourmines = 0;
        if(index.first > 0){
            if(!revealed[index.first - 1][index.second]){
                if(board[index.first - 1][index.second] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first - 1, index.second));
            }
            if(index.second > 0 && !revealed[index.first - 1][index.second - 1]){
                if(board[index.first - 1][index.second - 1] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first - 1, index.second - 1));
            }
            if(index.second < board[0].size() - 1 && !revealed[index.first - 1][index.second + 1]){
                if(board[index.first - 1][index.second + 1] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first - 1, index.second + 1));
            }
        }

        if(index.first < board.size() - 1){
            if(!revealed[index.first + 1][index.second]){
                if(board[index.first + 1][index.second] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first + 1, index.second));
            }
            if(index.second > 0 && !revealed[index.first + 1][index.second - 1]){
                if(board[index.first + 1][index.second - 1] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first + 1, index.second - 1));
            }
            if(index.second < board[0].size() - 1 && !revealed[index.first + 1][index.second + 1]){
                if(board[index.first + 1][index.second + 1] == 'M')
                    neighbourmines++;
                else
                    unrevealedneighbours.push_back(make_pair(index.first + 1, index.second + 1));
            }
        }

        if(index.second > 0 && !revealed[index.first][index.second - 1]){
            if(board[index.first][index.second - 1] == 'M')
                    neighbourmines++;
            else
                unrevealedneighbours.push_back(make_pair(index.first, index.second - 1));
        }

        if(index.second < board[0].size() - 1 && !revealed[index.first][index.second + 1]){
            if(board[index.first][index.second + 1] == 'M')
                    neighbourmines++;
            else
                unrevealedneighbours.push_back(make_pair(index.first, index.second + 1));
        }
        if(neighbourmines == 0){
            board[index.first][index.second] = 'B';
            for(auto neighbour : unrevealedneighbours)
                reveal(board, revealed, neighbour);
        }
        else
            board[index.first][index.second] = neighbourmines + '0';
    }
};