#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones[32] = {0};
        for(int num : nums){
            if(num < 0){
                for(int i = 0; i < 32; i++){
                    ones[i] += num & 1;
                    num >>= 1;
                }
            }
            else{
                for(int i = 0; num; i++){
                    ones[i] += num & 1;
                    num >>= 1;
                }
            }
        }
        int ret = 0;
        for(int i = 31; i >= 0; i--)
            ret = (ret << 1) + ones[i] % 3;
        return ret;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};