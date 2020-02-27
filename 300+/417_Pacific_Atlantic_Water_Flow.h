#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) { // BFS
        if(matrix.empty() || matrix[0].empty()) return vector<vector<int>>();
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> CanFlow2Pacific(m, vector<bool>(n, false));
        vector<vector<bool>> CanFlow2Atlantic(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            CanFlow2Pacific[0][i] = true;
            q.push(make_pair(0, i));
        }
        for(int i = 1; i < m; i++){
            CanFlow2Pacific[i][0] = true;
            q.push(make_pair(i, 0));
        }
        bfs(matrix, CanFlow2Pacific, q);
        for(int i = 0; i < n; i++){
            CanFlow2Atlantic[m - 1][i] = true;
            q.push(make_pair(m - 1, i));
        }
        for(int i = 0; i < m - 1; i++){
            CanFlow2Atlantic[i][n - 1] = true;
            q.push(make_pair(i, n - 1));
        }
        bfs(matrix, CanFlow2Atlantic, q);
        vector<vector<int>> ret;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(CanFlow2Pacific[i][j] && CanFlow2Atlantic[i][j])
                    ret.push_back({i, j});
        return ret;
    }

private:
    int m, n;
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& rslt, queue<pair<int,int>>& q){
        while(!q.empty()){
            pair<int,int> index = q.front();
            q.pop();
            if(index.first > 0 && matrix[index.first - 1][index.second] >= matrix[index.first][index.second] && !rslt[index.first - 1][index.second]){
                q.push(make_pair(index.first - 1, index.second));
                rslt[index.first - 1][index.second] = true;
            }
            if(index.first < m - 1 && matrix[index.first + 1][index.second] >= matrix[index.first][index.second] && !rslt[index.first + 1][index.second]){
                q.push(make_pair(index.first + 1, index.second));
                rslt[index.first + 1][index.second] = true;
            }
            if(index.second > 0 && matrix[index.first][index.second - 1] >= matrix[index.first][index.second] && !rslt[index.first][index.second - 1]){
                q.push(make_pair(index.first, index.second - 1));
                rslt[index.first][index.second - 1] = true;
            }
            if(index.second < n - 1 && matrix[index.first][index.second + 1] >= matrix[index.first][index.second] && !rslt[index.first][index.second + 1]){
                q.push(make_pair(index.first, index.second + 1));
                rslt[index.first][index.second + 1] = true;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) { //DFS
        if(matrix.empty() || matrix[0].empty()) return vector<vector<int>>();
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> CanFlow2Pacific(m, vector<bool>(n, false));
        vector<vector<bool>> CanFlow2Atlantic(m, vector<bool>(n, false));
        for(int j = 0; j < n; j++) dfs(0, j, matrix, CanFlow2Pacific);
        for(int i = 1; i < m; i++) dfs(i, 0, matrix, CanFlow2Pacific);
        for(int j = 0; j < n; j++) dfs(m - 1, j, matrix, CanFlow2Atlantic);
        for(int i = 0; i < m - 1; i++) dfs(i, n - 1, matrix, CanFlow2Atlantic);
        vector<vector<int>> ret;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(CanFlow2Pacific[i][j] && CanFlow2Atlantic[i][j])
                    ret.push_back({i, j});
        return ret;
    }

private:
    int m, n;
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& rslt){
        rslt[i][j] = true;
        if(i > 0 && matrix[i - 1][j] >= matrix[i][j] && !rslt[i - 1][j])
            dfs(i - 1, j, matrix, rslt);
        if(i < m - 1 && matrix[i + 1][j] >= matrix[i][j] && !rslt[i + 1][j])
            dfs(i + 1, j, matrix, rslt);
        if(j > 0 && matrix[i][j - 1] >= matrix[i][j] && !rslt[i][j - 1])
            dfs(i, j - 1, matrix, rslt);
        if(j < n - 1 && matrix[i][j + 1] >= matrix[i][j] && !rslt[i][j + 1])
            dfs(i, j + 1, matrix, rslt);
    }
};