#include <vector>
#include <string>
#include <map>
#include <climits>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        vector<int> noduplicateA;
        vector<int> count;
        preprocess(A, noduplicateA, count);
        int n = noduplicateA.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int s = sqrt(noduplicateA[i] + noduplicateA[j]);
                if(s * s == noduplicateA[i] + noduplicateA[j]){
                    adj[i].push_back(j);
                    if(i != j)
                        adj[j].push_back(i);
                }
            }
        }

        vector<int> visitedtimes(n, 0);
        int ret = 0;
        for(int i = 0; i < n; i++)
            ret += dfs(i, adj, count, visitedtimes, 0, A.size());
        return ret;
    }

private:
    void preprocess(vector<int>& A, vector<int>& noduplicate,vector<int>& count){
        if(A.empty()) return;
        sort(A.begin(), A.end());
        noduplicate.push_back(A[0]);
        count.push_back(1);
        for(int i = 1, j = 0; i < A.size(); i++){
            if(A[i] == A[i - 1]){
                count[j]++;
            }
            else{
                noduplicate.push_back(A[i]);
                count.push_back(1);
                j++;
            }
        }
    }

    int dfs(int v, vector<vector<int>>& adj, vector<int>& count, vector<int>& visitedtimes, int pathlen, int targetlen){
        if(visitedtimes[v] == count[v]) return 0;
        if(pathlen + 1 == targetlen) return 1;
        visitedtimes[v]++;
        int paths = 0;
        for(int next : adj[v])
            paths += dfs(next, adj, count, visitedtimes, pathlen + 1, targetlen);
        visitedtimes[v]--;
        return paths;
    }
};