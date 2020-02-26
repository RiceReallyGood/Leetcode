#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long curr_range = 0;
        int patch = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > curr_range + 1){
                patch++;
                curr_range += curr_range + 1;
                i--;
            }
            else
                curr_range += nums[i];
            if(curr_range >= n)
                return patch;
        }

        while(curr_range < n){
            patch++;
            curr_range += curr_range + 1;
        }
        return patch;
    }
};

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long curr_range = 0; //range[0,curr_range]
        int patch = 0;
        int index = 0;
        while(curr_range < n){
            if(index < nums.size() && nums[index] <= curr_range + 1)
                curr_range += nums[index++];
            else{
                patch++;
                curr_range += curr_range + 1;
            }
        }
        return patch;
    }
};

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long curr_range = 1; //range[0,curr_range)
        int patch = 0;
        int index = 0;
        while(curr_range <= n){
            if(index < nums.size() &&  nums[index] <= curr_range)
                curr_range += nums[index++];
            else{
                patch++;
                curr_range += curr_range;
            }
        }
        return patch;
    }
};