#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) : rectangles(rects), rows(rects.size()), pointsum(rects.size()), cols(rects.size()) {
        totalpoins = 0;
        for(int i = 0; i < rects.size(); i++){
            cols[i] = rects[i][2] - rects[i][0] + 1;
            rows[i] = rects[i][3] - rects[i][1] + 1;
            pointsum[i] = totalpoins + cols[i] * rows[i];
            totalpoins = pointsum[i];
        }
    }
    
    vector<int> pick() {
        int p = rand() % totalpoins;
        int index = upper_bound(pointsum.begin(), pointsum.end(), p) - pointsum.begin();
        p = index == 0 ? p : p - pointsum[index - 1];
        return {p % cols[index] + rectangles[index][0], p / cols[index] + rectangles[index][1]};
    }

private:
    vector<vector<int>>& rectangles;
    vector<int> rows;
    vector<int> cols;
    vector<int> pointsum;
    int totalpoins;
};