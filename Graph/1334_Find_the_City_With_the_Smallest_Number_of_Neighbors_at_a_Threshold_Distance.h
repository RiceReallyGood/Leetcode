#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for(auto& edge : edges){
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int minneighbour = n - 1;
        int minneighbourvertex = -1;
        for(int i = 0; i < n; i++){
            int neighbours = 0;
            for(int j = 0; j < n; j++)
                if(j != i && dp[i][j] <= distanceThreshold)
                    neighbours++;
            if(neighbours <= minneighbour){
                minneighbour = neighbours;
                minneighbourvertex = i;
            }
        }
        return minneighbourvertex;
    }
};