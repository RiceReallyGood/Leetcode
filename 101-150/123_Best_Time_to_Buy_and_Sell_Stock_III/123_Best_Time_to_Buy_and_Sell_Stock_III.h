#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++)
            maxprofit = max(maxprofit, maxProfit(prices, 0, i) + maxProfit(prices, i, prices.size()));
        return maxprofit;
    }

private:
    int maxProfit(vector<int>& prices, int l,int r){
        int buy = prices[l];
        int sell = prices[l];
        int maxprofit = 0;
        for(int i = l; i < r; i++){
            if(prices[i] > sell){
                sell = prices[i];
                maxprofit = max(maxprofit,sell - buy);
            }
            else if(prices[i] < buy)
                buy = sell = prices[i];
        }
        return maxprofit;
    }
};