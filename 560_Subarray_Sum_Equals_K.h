#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // O(n^2)
    int subarraySum2(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    ++res;
                }
            }
        }
        return res;
    }

    // O(n)
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> sumCount;
        int sum = 0;
        sumCount[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int target = sum - k;

            auto it = sumCount.find(target);
            if (it != sumCount.end()) {
                res += it->second;
            }

            ++sumCount[sum];
        }
        return res;
    }
};