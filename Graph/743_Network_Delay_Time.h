#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> adj(N + 1);
        for(int i = 0; i < times.size(); i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        vector<int> dist(N + 1, INT_MAX);
        vector<int> determined(N + 1, false);
        dist[K] = 0;
        while(true){
            int currnode = 0;
            for(int i = 1; i <= N; i++){
                if(dist[i] < dist[currnode] && !determined[i])
                    currnode = i;
            }
            if(currnode == 0)
                break;
            determined[currnode] = true;
            for(auto& neighbour : adj[currnode]){
                dist[neighbour.first] = min(dist[neighbour.first], dist[currnode] + neighbour.second);
            }
        }

        int ret = 0;
        for(int i = 1; i <= N; i++){
            if(!determined[i]) return -1;
            ret = max(ret, dist[i]);
        }
        return ret;
    }
};