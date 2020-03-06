#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> combinations(amount + 1, 0);
        combinations[0] = 1;
        for(int coin : coins){
            for(int j = coin; j <= amount; j++)
                combinations[j] += combinations[j - coin];
        }
        return combinations[amount];
    }
};