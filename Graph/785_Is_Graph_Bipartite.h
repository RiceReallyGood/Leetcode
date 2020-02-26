#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<bool> determined(N, false);
        vector<bool> samewith0(N, true);
        for(int i = 0; i < N; i++){
            if(determined[i]) continue;
            determined[i] = true;
            samewith0[i] = true;
            if(!dfs(i, graph, determined, samewith0))
                return false;
        }
        return true;
    }

private:
    bool dfs(int v, vector<vector<int>>& graph, vector<bool>& determined, vector<bool>& samewith0){
        for(int i = 0; i < graph[v].size(); i++){
            if(determined[graph[v][i]]){
                if(samewith0[v] == samewith0[graph[v][i]])
                    return false;
                else
                    continue;
            }
            determined[graph[v][i]] = true;
            samewith0[graph[v][i]] = !samewith0[v];
            if(!dfs(graph[v][i], graph, determined, samewith0))
                return false;
        }
        return true;
    }
};