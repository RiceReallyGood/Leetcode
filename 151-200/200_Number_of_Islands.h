#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

private:
    void DFS(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '2';
        if(row != 0 && grid[row - 1][col] == '1')
            DFS(grid, row - 1, col);
        if(row !=  grid.size() - 1 && grid[row + 1][col] == '1')
            DFS(grid, row + 1, col);
        if(col != 0 && grid[row][col - 1] == '1')
            DFS(grid, row, col - 1);
        if(col != grid[0].size() - 1 && grid[row][col + 1] == '1')
            DFS(grid, row, col + 1);
    }
};