#include <vector>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 0;
        stack<int> s;
        s.push(0);
        int i = 1;
        for(; i < nums.size() && nums[i] >= nums[i - 1]; i++){
            s.push(i);
        }
        int maxheight = nums[s.top()];
        for(; i < nums.size(); i++){
            if(nums[i] >= maxheight){
                maxheight = nums[i];
                continue;
            }
            while(!s.empty() && nums[i] < nums[s.top()])
                s.pop();
            ret = i - (s.empty() ? -1 : s.top());
        }
        return ret;
    }
};