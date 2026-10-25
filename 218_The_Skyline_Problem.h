#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        
        for (const auto& building : buildings) {
            edges.emplace_back(building[0], building[2]);
            edges.emplace_back(building[1], -building[2]);
        }

        sort(edges.begin(), edges.end());

        multiset<int> buildingsInRange;
        vector<vector<int>> res;
        int leftHeight = 0;
        for (int i = 0; i < edges.size();) {
            int x = edges[i].first;
            while (i < edges.size() && edges[i].first == x) {
                if (edges[i].second > 0) {
                    buildingsInRange.insert(edges[i].second);
                } else {
                    buildingsInRange.erase(buildingsInRange.find(-edges[i].second));
                }

                ++i;
            }

            auto it = buildingsInRange.rbegin();
            int height = it == buildingsInRange.rend() ? 0 : *it;

            if (height != leftHeight) {
                res.push_back({x, height});
                leftHeight = height;
            }
        }
        return res;
    }
};