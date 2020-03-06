#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return nums;
        int N = nums.size();
        int maxindex = 0;
        for(int i = 1; i < N; i++)
            if(nums[i] > nums[maxindex]) maxindex = i;
        vector<int> ret(N);
        stack<int> s;
        for(int i = maxindex; i >= 0; i--){
            while(!s.empty() && s.top() <= nums[i]) s.pop();
            if(s.empty()) ret[i] = -1;
            else ret[i] = s.top();
            s.push(nums[i]);
        }

        for(int i = N - 1; i > maxindex; i--){
            while(!s.empty() && s.top() <= nums[i]) s.pop();
            if(s.empty()) ret[i] = -1;
            else ret[i] = s.top();
            s.push(nums[i]);
        }
        return ret;
    }
};