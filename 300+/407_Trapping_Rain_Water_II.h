#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m <= 2) return 0;
        int n = heightMap[0].size();
        if(n <= 2) return 0;
        priority_queue<Node, vector<Node>, comp> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int j = 0; j < n; j++){
            pq.push(Node(0, j, heightMap[0][j]));
            pq.push(Node(m - 1, j, heightMap[m - 1][j]));
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        for(int i = 1; i < m - 1; i++){
            pq.push(Node(i, 0, heightMap[i][0]));
            pq.push(Node(i, n - 1, heightMap[i][n -1]));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        int maxheight = 0;
        int ret = 0;
        while(!pq.empty()){
            Node node = pq.top();
            pq.pop();
            if(node.h > maxheight) maxheight = node.h;
            else ret += maxheight - node.h;

            if(node.x > 0 && !visited[node.x - 1][node.y]){
                pq.push(Node(node.x - 1, node.y, heightMap[node.x - 1][node.y]));
                visited[node.x - 1][node.y] = true;
            }
            if(node.x < m - 1 && !visited[node.x + 1][node.y]){
                pq.push(Node(node.x + 1, node.y, heightMap[node.x + 1][node.y]));
                visited[node.x + 1][node.y] = true;
            }
            if(node.y > 0 && !visited[node.x][node.y - 1]){
                pq.push(Node(node.x, node.y - 1, heightMap[node.x][node.y - 1]));
                visited[node.x][node.y - 1] = true;
            }
            if(node.y < n - 1 && !visited[node.x][node.y + 1]){
                pq.push(Node(node.x, node.y + 1, heightMap[node.x][node.y + 1]));
                visited[node.x][node.y + 1] = true;
            }
        }
        return ret;
    }

private:
    class Node{
    public:
        int x;
        int y;
        int h;
        Node(int i, int j, int height) : x(i), y(j), h(height) {}
    };
    class comp{
    public:
        bool operator()(const Node& n1, const Node& n2) { return n1.h > n2.h; }
    };
};