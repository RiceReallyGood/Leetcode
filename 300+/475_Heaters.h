#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int r = 0;
        for(int i = 0; i <houses.size(); i++){
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if(it == heaters.begin())
                r = max(r, *it - houses[i]);
            else if(it == heaters.end())
                r = max(r, houses[i] - *(it - 1));
            else
                r = max(r, min(*it - houses[i], houses[i] - *(it - 1)));
        }
        return r;
    }
};