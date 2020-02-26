#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int visitedPorts = 1;
        set<string> ap_set;
        for(auto& v : tickets){
            ap_set.insert(v[0]);
            ap_set.insert(v[1]);
            visitedPorts++;
        }
        vector<string> airports(ap_set.begin(), ap_set.end());
        unordered_map<string, int> order;
        for(int i = 0; i < airports.size(); i++)
            order[airports[i]] = i;
        vector<multiset<int>> destinations(airports.size());
        for(auto& v : tickets)
            destinations[order[v[0]]].insert(order[v[1]]);
        vector<int> path;
        path.push_back(order["JFK"]);
        recurse(destinations, visitedPorts, path);
        vector<string> realpath;
        for(int n : path)
            realpath.push_back(airports[n]);
        return realpath;
    }

private:
    bool recurse(vector<multiset<int>>& destinations, int visitedPorts, vector<int>& path){
        int lastport = path.back();
        if(destinations[lastport].empty()) return path.size() == visitedPorts;
        set<int> trail(destinations[lastport].begin(), destinations[lastport].end());
        for(int nextport : trail){
            path.push_back(nextport);
            destinations[lastport].erase(destinations[lastport].find(nextport));
            if(recurse(destinations, visitedPorts, path))
                return true;
            destinations[lastport].insert(nextport);
            path.pop_back();
        }
        return false;
    }
};

class Solution {
public:
    unordered_map<string, multiset<string>> adj; // adjacency list of graph;
    vector<string> ans;

    void dfs(string v){
        while (adj[v].size()){
            string next = *adj[v].begin();
            adj[v].erase(adj[v].begin());
            dfs(next);
        }
        ans.push_back(v);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets){
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs("JFK");
        return vector<string>(ans.rbegin(),ans.rend());
    }
};