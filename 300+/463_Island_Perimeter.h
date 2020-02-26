#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++)
                if(grid[i - 1][j] != grid[i][j])
                    perimeter++;
            for(int j = 1; j < n; j++)
                if(grid[i][j - 1] != grid[i][j])
                    perimeter++;
            perimeter += grid[i][0] + grid[i][n - 1];
        }
        for(int j = 0; j < n; j++)
            perimeter += grid[m - 1][j] + grid[0][j];
        for(int j = 1; j < n; j++)
            if(grid[0][j - 1] != grid[0][j])
                perimeter++;
        perimeter += grid[0][0] + grid[0][n - 1];
        return perimeter;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid){
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    if(i != 0 && grid[i - 1][j] == 1) perimeter -= 2;
                    if(j != 0 && grid[i][j - 1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;  
    }
};