#include <vector>
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

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int ret = 0;
        int leftbound = 0;
        while(leftbound < n - 1 && nums[leftbound + 1] >= nums[leftbound])
            leftbound++;

        int maxheight = nums[leftbound];
        for(int i = leftbound + 1; i < n; i++){
            if(nums[i] >= maxheight){
                maxheight = nums[i];
                continue;
            }
            while(leftbound != -1 && nums[i] < nums[leftbound])
                leftbound--;
            ret = i - leftbound;
        }
        return ret;
    }
};