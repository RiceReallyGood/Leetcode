#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> red_adj(n), blue_adj(n);
        for(auto& v : red_edges)
            red_adj[v[0]].push_back(v[1]);
        for(auto& v : blue_edges)
            blue_adj[v[0]].push_back(v[1]);
        priority_queue<Node, vector<Node>,comp> pq;
        pq.push(Node(0, 0, true));
        pq.push(Node(0, 0, false));
        vector<bool> visited_red(n, false), visited_blue(n, false);
        vector<int> ret(n, INT_MAX);
        while(!pq.empty()){
            Node node = pq.top();
            pq.pop();
            if(node.lastcolor){
                visited_red[node.id] = true;
                for(int next : blue_adj[node.id]){
                    if(!visited_blue[next])
                        pq.push(Node(next, node.dist + 1, false));
                }
            }
            else{
                visited_blue[node.id] = true;
                for(int next : red_adj[node.id]){
                    if(!visited_red[next])
                        pq.push(Node(next ,node.dist + 1, true));
                }
            }
            ret[node.id] = min(ret[node.id], node.dist);
        }
        for(int i = 0; i < n; i++)
            if(ret[i] == INT_MAX)
                ret[i] = -1;
        return ret;
    }
private:
    class Node{
    public:
        int id;
        int dist;
        bool lastcolor;
        Node(int id_, int distance, bool color) : id(id_), dist(distance), lastcolor(color) {}
    };

    class comp{
    public:
        bool operator()(const Node& n1, const Node& n2) { return n1.dist > n2.dist; }
    };
};