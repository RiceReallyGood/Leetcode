#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty())
            return false;
        vector<int> increaseset;
        int found = 0;
        for(int i = 0; i < nums.size(); i++){
            int index = increaseset.size();
            while(index > 0 && increaseset[index - 1] >= nums[i])
                index--;
            if(index == increaseset.size()){
                increaseset.push_back(nums[i]);
                if(increaseset.size() == 3)
                    return true;
            }
            else
                increaseset[index] = nums[i]; 
        }
        return false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > big)
                return true;

            if(nums[i] <= small)
                small = nums[i];
            else
                big = nums[i];
        }
        return false;
    }
};