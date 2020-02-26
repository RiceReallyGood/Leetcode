#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<int> unchanges;
        unordered_set<int> edge;
        for(int j = 0; j < cols; j++){
            if(board[0][j] == 'O')  edge.insert(j);
            if(board[rows - 1][j] == 'O') edge.insert((rows - 1) * cols + j);
        }
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O') edge.insert(i * cols);
            if(board[i][cols - 1] == 'O') edge.insert(i * cols + cols - 1);
        }

        while(!edge.empty()){
            int point = *(edge.begin());
            edge.erase(point);
            unchanges.insert(point);
            vector<int> neighbours;
            int i = point / cols, j = point % cols;
            if(i != 0)
                neighbours.push_back((i - 1) * cols + j);
            if(i != rows - 1)
                neighbours.push_back((i + 1) * cols + j);
            if(j != 0)
                neighbours.push_back(i * cols + j - 1);
            if(j != cols - 1)
                neighbours.push_back(i * cols + j + 1);
            
            for(int neighbour : neighbours)
                if(board[neighbour / cols][neighbour % cols] == 'O' &&
                    unchanges.find(neighbour) == unchanges.end())
                    edge.insert(neighbour);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(unchanges.find(i * cols + j) != unchanges.end())
                    continue;
                board[i][j] = 'X';
            }
        }
    }
};