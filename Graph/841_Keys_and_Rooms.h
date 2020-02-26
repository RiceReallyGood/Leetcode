#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> visited(N, false);
        dfs(0, rooms, visited);
        for(int i = 0; i < N; i++)
            if(!visited[i]) return false;
        return true;
    }

private:
    void dfs(int v, vector<vector<int>>& rooms, vector<bool>& visited){
        if(!visited[v]){
            visited[v] = true;
            for(int next : rooms[v])
                dfs(next, rooms, visited);
        }
    }
};