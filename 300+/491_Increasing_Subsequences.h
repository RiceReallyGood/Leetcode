#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sequence;
        vector<vector<int>> ret;
        vector<int> previndex(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; --j){
                if(nums[j] == nums[i]){
                    previndex[i] = j;
                    break;
                }
            }
        }
        recurse(nums, previndex, -1, 0, sequence, ret);
        return ret;
    }

private:
    void recurse(vector<int>& nums, vector<int>& previndex, int lastindex, int index, vector<int>& sequence, vector<vector<int>>& ret){
        if(index == nums.size()) return;
        if(sequence.empty()){
            if(previndex[index] == -1){
                sequence.push_back(nums[index]);
                recurse(nums, previndex, index, index + 1, sequence, ret);
                sequence.pop_back();
            }
        }
        else if(sequence.back() <= nums[index]){
            if(lastindex >= previndex[index]){
                sequence.push_back(nums[index]);
                ret.push_back(sequence);
                recurse(nums, previndex, index, index + 1, sequence, ret);
                sequence.pop_back();
            }
        }
        recurse(nums, previndex, lastindex, index + 1, sequence, ret);
    }
};