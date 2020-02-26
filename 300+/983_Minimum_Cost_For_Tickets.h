#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> mintotalcost(366, 0);
        costs[1] = min(costs[1], costs[2]);
        costs[0] = min(costs[0], costs[1]);
        int index = 0;
        for(int i = 1; i < 7; i++){
            if(index < days.size() && days[index] == i){
                mintotalcost[i] = min(mintotalcost[i - 1] + costs[0], costs[1]);
                index++;
            }
            else
                mintotalcost[i] = mintotalcost[i - 1];
        }

        for(int i = 7; i < 30; i++){
            if(index < days.size() && days[index] == i){
                mintotalcost[i] = min(min(mintotalcost[i - 1] + costs[0], mintotalcost[i - 7] + costs[1]), costs[2]);
                index++;
            }
            else
                mintotalcost[i] = mintotalcost[i - 1];
        }

        for(int i = 30; i < 366; i++){
            if(index < days.size() && days[index] == i){
                mintotalcost[i] = min(min(mintotalcost[i - 1] + costs[0], mintotalcost[i - 7] + costs[1]), mintotalcost[i - 30] + costs[2]);
                index++;
            }
            else
                mintotalcost[i] = mintotalcost[i - 1];
        }
        return mintotalcost[365];
    }
};