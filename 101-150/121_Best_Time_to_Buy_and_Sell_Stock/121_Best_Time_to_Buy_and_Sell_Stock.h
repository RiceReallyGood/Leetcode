#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        
        int buy = prices[0];
        int sell = prices[0];
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy)
                buy = sell = prices[i];
            else if(prices[i] > sell){
                sell = prices[i];
                maxprofit = max(maxprofit, sell - buy);
            }
        }
        return maxprofit;
    }
};