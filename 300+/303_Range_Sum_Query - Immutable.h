#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : psum(nums.size() + 1, 0){
        for(int i = 0; i < nums.size(); i++)
            psum[i + 1] = psum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return psum[j + 1] - psum[i];
    }

private:
    vector<int> psum;
};