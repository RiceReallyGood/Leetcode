#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nNoneZeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nNoneZeros++] = nums[i];
            }
        }

        for (int i = nNoneZeros; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};