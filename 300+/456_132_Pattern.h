#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Solution { //28ms
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<pair<int,int>> intervals;
        intervals.push_back({nums[0], nums[0]});
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= intervals.back().first){
                if(intervals.back().second - intervals.back().first < 2)
                    intervals.pop_back();
                intervals.push_back({nums[i], nums[i]});
            }
            else if(nums[i] < intervals.back().second)
                return true;
            else{
                pair<int, int> interval = intervals.back();
                intervals.pop_back();
                interval.second = nums[i];
                while(!intervals.empty()){
                    if(nums[i] >= intervals.back().second)
                        intervals.pop_back();
                    else if(nums[i] > intervals.back().first)
                        return true;
                    else
                        break;
                }
                intervals.push_back(interval);
            }
        }
        return false;
    }
};

class Solution { //548ms
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int prevmin = INT_MAX;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] <= prevmin){
                prevmin = nums[j];
                continue;
            }
            for(int k = j + 1; k < nums.size(); k++){
                if(nums[k] < nums[j] && prevmin < nums[k])
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        vector<int> prevmin(nums.size(), 0);
        prevmin[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            prevmin[i] = min(prevmin[i - 1], nums[i]);
        stack<int> s;
        for(int i = nums.size() - 1; i >= 0; --i){
            while(!s.empty() && s.top() <= prevmin[i])
                s.pop();
            if(s.empty() || nums[i] < s.top())
                s.push(nums[i]);
            else if(nums[i] > s.top())
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) { // time: O(n); space: O(n)
        int s3 = numeric_limits<int>::min();
        stack<int> st; // monotonous descreasing stack
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s3) return true;
            while (!st.empty() && nums[i] > st.top()) {
                s3 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};