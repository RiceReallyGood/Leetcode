#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) { //620 ms
        int N = points.size();
        vector<unordered_map<int, int>> distcount(N);
        for(int i = 0;i < N; i++){
            for(int j = i + 1; j < N; j++){
                int sq = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
                        + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                distcount[i][sq]++;
                distcount[j][sq]++;
            }
        }

        int ret = 0;
        for(int i = 0; i < N; i++){
            for(auto it = distcount[i].begin(); it != distcount[i].end(); it++)
                ret += (it->second) * (it->second - 1);
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) { //444 ms
        int N = points.size();
        int ret = 0;
        for(int i = 0; i < N; i++){
            unordered_map<int, int> distcount;
            for(int j = 0; j < N; j++){
                int sq = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
                        + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                distcount[sq]++;
            }
            for(auto it : distcount)
                ret += it.second * (it.second - 1);
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) { //168 ms
        int N = points.size();
        vector<vector<int>> dist(N, vector<int>(N, 0));
        for(int i = 0; i < N ; i++)
            for(int j = i + 1; j < N; j++)
                dist[i][j] = dist[j][i] = pow(points[i][0] - points[j][0], 2)
                                        + pow(points[i][1] - points[j][1], 2);
        
        int ret = 0;
        for(int i = 0; i < N; i++){
            sort(dist[i].begin(), dist[i].end());
            int count = 1;
            for(int j = 1; j <= N; j++){
                if(j < N && dist[i][j] == dist[i][j - 1]) count++;
                else{
                    ret += count * (count - 1);
                    count = 1;
                }
            }
        }
        return ret;
    }
};