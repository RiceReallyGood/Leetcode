#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> sw(nums.begin(), nums.begin() + k);
        sort(sw.begin(), sw.end());
        int center = k / 2;
        vector<double> ret;
        if(k & 1)
            ret.push_back(sw[center]);
        else
            ret.push_back((double(sw[center]) + double(sw[center - 1])) / 2.);
        for(int i = k; i < nums.size(); i++){
            int idx1 = lower_bound(sw.begin(), sw.end(), nums[i - k]) - sw.begin();
            int idx2 = lower_bound(sw.begin(), sw.end(), nums[i]) - sw.begin();
            if(idx1 <= idx2){
                while(idx1 + 1 < idx2){
                    sw[idx1] = sw[idx1 + 1];
                    idx1++;
                }
                sw[idx1] = nums[i];
            }
            else{
                while(idx1 > idx2){
                    sw[idx1] = sw[idx1 - 1];
                    idx1--;
                }
                sw[idx1] = nums[i];
            }
            if(k & 1)
                ret.push_back(sw[center]);
            else
                ret.push_back((double(sw[center]) + double(sw[center - 1])) / 2.);
        }
        return ret;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> sw(nums.begin(), nums.begin() + k);
        vector<double> ret;
        auto center = next(sw.begin(), k / 2);
        for(int i = k; ; i++){
            if(k & 1)
                ret.push_back(*center);
            else
                ret.push_back((double(*center) + double(*prev(center))) / 2.);
            if(i == nums.size())
                return ret;
            sw.insert(nums[i]);
            if(nums[i] < *center)
                center--;
            if(nums[i - k] <= *center)
                center++;
            sw.erase(sw.lower_bound(nums[i - k]));
        }
        return ret;
    }
};