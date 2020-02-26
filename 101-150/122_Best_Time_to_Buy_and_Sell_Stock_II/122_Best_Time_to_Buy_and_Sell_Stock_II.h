#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buytime = 0;
        int selltime = 0;
        while(buytime < prices.size()){
            while(selltime < prices.size() - 1 && prices[selltime + 1] >= prices[selltime])
                selltime++;
            profit += prices[selltime] - prices[buytime];
            selltime++;
            buytime = selltime;
        }
        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        
        return profit;
    }
};