#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

class Solution { //TLE
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        return recurse(coins, 0, amount);
    }

private:
    int recurse(vector<int>& coins, int index, int amount){
        if(index == coins.size())
            return -1;
        
        int maxcoin_num = amount / coins[index];
        if(amount % coins[index] == 0)
            return maxcoin_num;
        
        int mincoins = -1;
        for(int i = maxcoin_num; i >= 0; --i){
            int rest = recurse(coins, index + 1, amount - i * coins[index]);
            if(rest != -1){
                if(mincoins == -1)
                    mincoins = rest + i;
                else
                    mincoins = min(mincoins, rest + i);
            }
        }
        return mincoins;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> productions = {0};
        vector<int> p(coins.size(), 0);
        vector<int> next(coins);
        vector<int> mincoins = {0};
        while(true){
            int minnext = next[0];
            for(int i = 1; i < next.size(); i++)
                if(next[i] < minnext)
                    minnext = next[i];
            if(minnext > amount)
                break;
            productions.push_back(minnext);
            mincoins.push_back(INT_MAX);
            for(int i = 0; i < next.size(); i++){
                if(next[i] == minnext){
                    mincoins.back() = min(mincoins.back(), mincoins[p[i]] + 1);
                    p[i]++;
                    next[i] = coins[i] + productions[p[i]];
                }
            }
        }
        if(productions.back() == amount)
            return mincoins.back();
        return -1;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount + 1, amount + 1);
        mincoins[0] = 0;
        int next;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] <= i)
                    mincoins[i] = min(mincoins[i], mincoins[i - coins[j]] + 1);
            }
        }
        return mincoins[amount] == amount + 1 ? -1 : mincoins[amount];
    }
};