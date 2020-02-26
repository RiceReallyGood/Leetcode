#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        if(max_k == 0 || prices.empty())
            return 0;
        
        int sz = prices.size();
        vector<vector<int>> keep(max_k + 1,vector<int>(sz));
        vector<vector<int>> free(max_k + 1,vector<int>(sz));

        for(int k = 0; k <= max_k; k++){
            free[k][0] = 0;
            keep[k][0] = -prices[0];
        }
        for(int i = 0; i < sz; i++){
            free[0][i] = 0;
            keep[0][i] = INT_MIN;
        }

        for(int k = 1; k <= max_k; k++){
            for(int i = 1; i < sz; i++){
                free[k][i] = max(free[k][i - 1], keep[k][i - 1] + prices[i]);
                keep[k][i] = max(keep[k][i - 1], free[k - 1][i - 1] - prices[i]);
            }
        }
        return free[max_k][sz - 1];
    }
};


class Solution2 {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        if(max_k == 0 || prices.empty())
            return 0;
        
        int sz = prices.size();
        if(max_k > sz / 2)
            return maxProfit_inf(prices);

        vector<int> keep(sz);
        vector<int> free(sz);

        keep[0] = -prices[0];
        free[0] = 0;
        for(int k = 1; k <= max_k; k++){
            for(int i = 1; i < sz; i++)
                keep[i] = max(keep[i - 1], free[i - 1] - prices[i]);

            for(int i = 1; i < sz; i++)
                free[i] = max(free[i - 1], keep[i - 1] + prices[i]); 
        }
        return free[sz - 1];
    }

private:
    int maxProfit_inf(vector<int>& prices){
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

class Solution3 {
public:
    int maxProfit(int max_k, vector<int>& prices) {
        if(max_k == 0 || prices.empty())
            return 0;
        
        int sz = prices.size();
        if(max_k >= sz / 2)
            return maxProfit_inf(prices);

        vector<int> keep(1 + max_k);
        vector<int> free(1 + max_k);

        for(int k = 0; k <= max_k; k++){
            free[k] = 0;
            keep[k] = INT_MIN;
        }

        for(int i = 0; i < sz; i++){
            for(int k = max_k; k >= 1; k--){
                free[k] = max(free[k], keep[k] + prices[i]);
                keep[k] = max(keep[k], free[k - 1] - prices[i]);
            }
        }
        return free[max_k];
    }

private:
    int maxProfit_inf(vector<int>& prices){
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