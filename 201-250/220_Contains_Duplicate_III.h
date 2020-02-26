#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k <= 0 || t < 0)
            return false;
        set<long> prevk;
        long lt = t;
        for(int i = 0; i < k && i < nums.size(); i++){
            if(prevk.lower_bound(long(nums[i]) - lt) != prevk.upper_bound(long(nums[i]) + lt))
                return true;
            prevk.insert(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            if(prevk.lower_bound(long(nums[i]) - lt) != prevk.upper_bound(long(nums[i]) + lt))
                return true;
            prevk.erase(nums[i - k]);
            prevk.insert(nums[i]);
        }
        return false;
    }
};