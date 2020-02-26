#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size();
        if(sz < 2)
            return 0;
        
        int free[sz];
        int keep[sz];

        free[0] = 0;
        keep[0] = -prices[0] - fee;

        for(int i = 1; i < sz; i++){
            keep[i] = max(keep[i - 1], free[i - 1] -prices[i] -fee);
            free[i] = max(free[i - 1], keep[i - 1] + prices[i]);
        }
        return free[sz - 1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size();
        if(sz < 2)
            return 0;
        
        int free = 0, keep = -prices[0] - fee;

        for(int i = 1; i < sz; i++){
            keep = max(keep, free - prices[i] -fee);
            free = max(free, keep + prices[i]);
        }
        return free;
    }
};