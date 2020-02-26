#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;
        if(stations.empty()) return -1;
        int n = stations.size();
        vector<int> dp(n + 1, 0);
        dp[0] = startFuel;
        for(int i = 0; i < n && stations[i][0] <= startFuel; i++)
            dp[i + 1] = startFuel;
        for(int s = 1; s <= n; s++){
            if(dp[s - 1] < stations[s - 1][0]) return -1;
            int prev = dp[s], curr;
            dp[s] = dp[s - 1] + stations[s - 1][1];
            for(int i = s; i < n; i++){
                if(dp[i] < stations[i][0]) break;
                curr = dp[i + 1];
                if(prev < stations[i][0]) dp[i + 1] = dp[i];
                else dp[i + 1] = max(prev + stations[i][1], dp[i]);
                prev = curr;
            }
            if(dp[n] >= target) return s;
        }
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;
        if(stations.empty()) return -1;
        int n = stations.size();
        vector<int> dp(n + 1, 0);
        vector<int> temp(n + 1);
        dp[0] = startFuel;
        for(int i = 0; i < n && stations[i][0] <= startFuel; i++)
            dp[i + 1] = startFuel;
        for(int s = 1; s <= n; s++){
            if(dp[s - 1] < stations[s - 1][0]) return -1;
            temp[s] = dp[s - 1] + stations[s - 1][1];
            for(int i = s; i < n; i++){
                if(temp[i] < stations[i][0]) break;
                if(dp[i] < stations[i][0]) temp[i + 1] = temp[i];
                else temp[i + 1] = max(dp[i] + stations[i][1], temp[i]);
            }
            if(temp[n] >= target) return s;
            swap(temp, dp);
        }
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;
        if(stations.empty()) return -1;
        int n = stations.size();
        vector<long> dp(n + 1, 0);
        dp[0] = startFuel;
        int minrequir = 0;
        for(int i = 0; i < n; i++){
            for(int t = i; t >= minrequir; t--){
                if(dp[t] < stations[i][0]){
                    minrequir = t + 1;
                    break;
                }
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
            }
        }
        for(int i = 0; i <= n; i++)
            if(dp[i] >= target) return i;
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int nextstation = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        int s = -1, farthesttogo = 0;
        while(!pq.empty()){
            farthesttogo += pq.top();
            pq.pop();
            s++;
            if(farthesttogo >= target) return s;
            while(nextstation < n && stations[nextstation][0] <= farthesttogo)
                pq.push(stations[nextstation++][1]);
        }
        return -1;
    }
};