#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> S1, S2;

        int sz = buildings.size();
        for(int i = 0; i < sz; i++){
            while(!S1.empty() && S1.back()[0] >= buildings[i][1]){
                S2.push_back(S1.back());
                S1.pop_back();
            }
            if(S2.empty() || S2.back()[0] != buildings[i][1])
                if(S1.empty())
                    S2.push_back({buildings[i][1], 0});
                else if(S1.back()[1] < buildings[i][2])
                    S2.push_back({buildings[i][1], S1.back()[1]});
                    
            while(!S1.empty() && S1.back()[0] >= buildings[i][0]){
                vector<int> rec = S1.back();
                S1.pop_back();
                if(rec[1] > buildings[i][2])
                    S2.push_back(rec);
                else if(!S1.empty() && S1.back()[1] > buildings[i][2])
                    S2.push_back({rec[0], buildings[i][2]});
            }
            if(S2.back()[0] != buildings[i][0] && (S1.empty() || S1.back()[1] < buildings[i][2]))
                    S2.push_back({buildings[i][0], buildings[i][2]});
            
            while(!S2.empty()){
                S1.push_back(S2.back());
                S2.pop_back();
            }
        }
        return S1;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> points;
        for(int i = 0; i < buildings.size(); i++){
            points.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            points.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(points.begin(), points.end());
        multiset<int> heights = {0};

        vector<vector<int>> ret;
        for(int i = 0; i < points.size(); i++){
            if(points[i].second < 0)
                heights.insert(-points[i].second);
            else
                heights.erase(heights.find(points[i].second));
            int maxheight = *(heights.rbegin());
            if(ret.empty() || ret.back()[1] != maxheight)
                ret.push_back({points[i].first, maxheight});
        }
        return ret;
    }
};