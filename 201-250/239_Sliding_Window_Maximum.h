#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        if(nums.size() < k || k == 0)
            return ret;
        for(int i = 0; i < k; i++){
            while(!q.empty() && q.front() < nums[i])
                q.pop_front();
            q.push_front(nums[i]);
        }
        ret.push_back(q.back());
        for(int i = k; i < nums.size(); i++){
            while(!q.empty() && q.front() < nums[i])
                q.pop_front();
            if(!q.empty() && q.back() == nums[i - k])
                q.pop_back();
            q.push_front(nums[i]);
            ret.push_back(q.back());
        }
        return ret;
    }
};