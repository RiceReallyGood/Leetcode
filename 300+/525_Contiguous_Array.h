#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> diff_index;
        diff_index[0] = -1;
        int diff = 0;
        int ret = 0;
        for(int i = 0; i < N; i++){
            if(nums[i] == 1) diff++;
            else diff--;
            if(diff_index.find(diff) == diff_index.end())
                diff_index[diff] = i;
            else
                ret = max(ret, i - diff_index[diff]);
        }
        return ret;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        vector<int> diff_index(2 * N + 1, N);
        diff_index[N] = -1;
        int diff = 0;
        int ret = 0;
        for(int i = 0; i < N; i++){
            if(nums[i] == 1) diff++;
            else diff--;
            if(diff_index[diff + N] == N) diff_index[diff + N] = i;
            else ret = max(ret, i - diff_index[diff + N]);
        }
        return ret;
    }
};