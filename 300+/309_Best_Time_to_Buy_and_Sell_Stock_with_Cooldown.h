#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz < 2)
            return 0;

        int free[sz];
        int keep[sz];

        free[0] = 0;
        free[1] = max(0, prices[1] - prices[0]);
        keep[0] = -prices[0];
        keep[1] = max(keep[0], -prices[1]);
        
        for(int i = 2; i < sz; i++){
            keep[i] = max(keep[i - 1], free[i - 2] - prices[i]);
            free[i] = max(free[i - 1], keep[i - 1] + prices[i]);
        }
        return free[sz - 1];
    }
};