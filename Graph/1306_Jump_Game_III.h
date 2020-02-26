#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        vector<bool> visited(N, 0);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0) return true;
            int next = curr + arr[curr];
            if(next < N && !visited[next]){
                q.push(next);
                visited[next] = true;
            }
            next = curr - arr[curr];
            if(next >= 0 && !visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
        return false;
    }
};