#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int unrob = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            int temp = unrob;
            unrob = max(rob, unrob);
            rob = temp + nums[i];
        }
        return max(rob, unrob);
    }
};