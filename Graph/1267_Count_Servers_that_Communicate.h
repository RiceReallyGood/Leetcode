#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_num(m, 0), col_num(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    row_num[i]++;
                    col_num[j]++;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && (row_num[i] > 1 || col_num[j] > 1))
                    ret++;
            }
        }
        return ret;
    }
};