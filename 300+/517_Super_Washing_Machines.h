#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int target = 0;
        for(auto& num : machines)
            target += num;
        if(target % n != 0) return -1;
        target /= n;
        int ret = 0, residual = 0;
        for(auto num : machines){
            int diff = num - target;
            residual += diff;
            ret = max(ret, max(abs(residual), diff));
        }
        return ret;
    }
};