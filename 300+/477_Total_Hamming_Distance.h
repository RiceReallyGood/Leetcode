#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int ones[30] = {0};
        for(int i = 0; i < nums.size(); i++){
            for(int shift = 0; shift < 30; shift++)
                if((nums[i] >> shift) & 1){
                    total += i - ones[shift];
                    ones[shift]++;
                }
                else
                    total += ones[shift];
        }
        return total;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0; 
        for (int i = 0; i < 30; ++i) {
            int ones = 0; 
            for (int num : nums) {
                if (num & (1 << i)) ++ones; 
            }
            total += ones * (nums.size() - ones);
        }
        return total;
    }
};