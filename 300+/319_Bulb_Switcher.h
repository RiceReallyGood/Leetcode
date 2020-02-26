#include <vector>
#include <cmath>
using namespace std;

class Solution { //TLE
public:
    int bulbSwitch(int n) {
        vector<bool> bulb(n + 1, true);
        for(int i = 2; i <= n; i++)
            for(int j = i; j <= n; j += i)
                bulb[j] = !bulb[j];

        int count = 0;    
        for(int i = 1; i<= n; i++)
            if(bulb[i])
                count++;
        return count;
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        return int(std::sqrt(n));
    }
};