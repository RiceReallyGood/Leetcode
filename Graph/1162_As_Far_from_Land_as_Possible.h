#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int,int>> q;
        bool nowater = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1){
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
                else
                    nowater = false;
            }
        }
        if(nowater) return -1;
        int dist = -1;
        while(!q.empty()){
            dist++;
            int levelcount = q.size();
            for(int i = 0; i < levelcount; i++){
                pair<int, int> index = q.front();
                q.pop();
                if(index.first > 0 && !visited[index.first - 1][index.second]){
                    q.push(make_pair(index.first - 1, index.second));
                    visited[index.first - 1][index.second] = true;
                }
                if(index.first < N - 1 && !visited[index.first + 1][index.second]){
                    q.push(make_pair(index.first + 1, index.second));
                    visited[index.first + 1][index.second] = true;
                }
                if(index.second > 0 && !visited[index.first][index.second - 1]){
                    q.push(make_pair(index.first, index.second - 1));
                    visited[index.first][index.second - 1] = true;
                }
                if(index.second < N - 1 && !visited[index.first][index.second + 1]){
                    q.push(make_pair(index.first, index.second + 1));
                    visited[index.first][index.second + 1] = true;
                }
            }
        }
        return dist;
    }
};