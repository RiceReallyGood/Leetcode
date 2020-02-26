#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stations = gas.size();
        int rest = gas[0] - cost[0];
        int minrest = rest;
        int minindex = 0;
        for(int i = 1; i < stations; i++){
            rest = rest + gas[i] - cost[i];
            if(rest < minrest){
                minindex = i;
                minrest = rest;
            }
        }
        if(rest < 0)
            return -1;
        return (minindex + 1) % stations;
    }
};