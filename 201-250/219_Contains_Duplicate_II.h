#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k <= 0)
            return false;
        unordered_set<int> prevk;
        for(int i = 0; i < k && i < nums.size(); i++){
            if(prevk.find(nums[i]) != prevk.end())
                return true;
            prevk.insert(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            if(prevk.find(nums[i]) != prevk.end())
                return true;
            prevk.erase(nums[i - k]);
            prevk.insert(nums[i]);
        }
        return false;
    }
};