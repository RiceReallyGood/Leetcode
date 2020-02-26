#include <vector>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<bool>> candidate(N, vector<bool>(4, true));
        vector<int> color(N, -1);
        vector<vector<int>> adj(N);
        for(auto& v : paths){
            adj[v[0] - 1].push_back(v[1] - 1);
            adj[v[1] - 1].push_back(v[0] - 1);
        }
        for(int i = 0; i < N; i++)
            dfs(0, candidate, color, adj);
        return color;
    }

private:
    void dfs(int v, vector<vector<bool>>& candidate, vector<int>& color, vector<vector<int>>& adj){
        if(color[v] == -1){
            for(int i = 0; i < 4; i++){
                if(candidate[v][i] == true){
                    color[v] = i + 1;
                    break;
                }
            }
            for(int neighbour : adj[v])
                candidate[neighbour][color[v] - 1] = false;
            for(int neighbour : adj[v])
                dfs(neighbour, candidate, color, adj);
        }
    }
};

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> color(N, -1);
        vector<vector<int>> adj(N);
        for(auto& v : paths){
            adj[v[0] - 1].push_back(v[1] - 1);
            adj[v[1] - 1].push_back(v[0] - 1);
        }
        for(int i = 0; i < N; i++){
            for(int c = 1; c <= 4; c++){
                bool clash = false;
                for(int neighbour : adj[i]){
                    if(color[neighbour] == c){
                        clash = true;
                        break;
                    }
                }
                if(!clash){
                    color[i] = c;
                    break;
                }
            }
        }
        return color;
    }
};