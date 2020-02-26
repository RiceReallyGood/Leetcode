#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.empty())
            return ret;
        vector<int> intervals;
        intervals.push_back(nums[0]);
        intervals.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == intervals.back() + 1)
                intervals.back()++;
            else{
                intervals.push_back(nums[i]);
                intervals.push_back(nums[i]);
            }
        }
        for(int i = 0; i < intervals.size(); i += 2){
            if(intervals[i] == intervals[i + 1])
                ret.push_back(to_string(intervals[i]));
            else
                ret.push_back(to_string(intervals[i]) + "->" + to_string(intervals[i + 1]));
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.empty())
            return ret;
        int start = nums[0], end = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == end + 1)
                end++;
            else{
                if(start == end)
                    ret.push_back(to_string(start));
                else
                    ret.push_back(to_string(start) + "->" + to_string(end));
                start = nums[i];
                end = nums[i];
            }
        }
        if(start == end)
            ret.push_back(to_string(start));
        else
            ret.push_back(to_string(start) + "->" + to_string(end));
        return ret;
    }
};