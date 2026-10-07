#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index_of;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int partner = target - num;
            if (index_of.find(partner) != index_of.end()) {
                return {index_of[partner], i};
            }
            index_of[num] = i;
        }
        return {-1, -1};
    }
};