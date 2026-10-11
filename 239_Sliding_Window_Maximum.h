#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        if (nums.size() < k) {
            return res;
        }

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());

        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] == dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.push_back(dq.front());
        }

        return res;
    }
};