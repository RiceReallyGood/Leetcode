#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<bool> determined(N, false);
        vector<bool> safe(N, false);
        vector<int> ret;
        for(int i = 0; i < N; i++){
            if(!determined[i])
                issafe(i, graph, determined, safe);
            if(safe[i])
                ret.push_back(i);
        }
        return ret;
    }

private:
    bool issafe(int v, vector<vector<int>>& graph, vector<bool>& determined, vector<bool>& safe){
        if(determined[v]) return safe[v];
        determined[v] = true;
        for(int next : graph[v]){
            if(!issafe(next, graph, determined, safe))
                return safe[v];
        }
        return safe[v] = true;
    }
};