#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            num_index[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return num_index[target][rand() % num_index[target].size()];
    }

private:
    map<int,vector<int>> num_index;
};