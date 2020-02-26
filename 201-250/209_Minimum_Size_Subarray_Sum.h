#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        int minlen = sz + 1;
        int i = 0, j = 0;
        while(j < sz){
            while(j < sz && sum < s)
                sum += nums[j++];
            if(sum < s)
                break;
            while(sum >= s)
                sum -= nums[i++];
            minlen = min(minlen, j - i + 1);
        }
        return minlen == sz + 1 ? 0 : minlen;
    }
};