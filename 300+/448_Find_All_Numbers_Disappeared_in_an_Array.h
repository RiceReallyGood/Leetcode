#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++){
            while(nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        vector<int> ret;
        for(int i = 0; i < N; i++){
            if(nums[i] != i + 1)
                ret.push_back(i + 1);
        }
        return ret;
    }
};