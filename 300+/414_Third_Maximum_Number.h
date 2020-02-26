#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> max3;
        for(int i = 0; i < nums.size(); i++){
            int j = 0;
            while(j < max3.size() && max3[j] < nums[i]) ++j;

            if(j < max3.size() && max3[j] == nums[i]) continue;

            if(max3.size() < 3){
                max3.push_back(nums[i]);
                for(int k = max3.size() - 1; k > j; --k)
                    max3[k] = max3[k - 1];
                max3[j] = nums[i];
            }
            else if(j > 0){
                for(int k = 0; k < j - 1; k++)
                    max3[k] = max3[k + 1];
                max3[j - 1] = nums[i];
            }
        }
        if(max3.size() < 3)
            return max3.back();
        else
            return max3[0];
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> max3;
        for(auto& n : nums){
            if(max3.find(n) != max3.end())
                continue;
            
            max3.insert(n);
            if(max3.size() > 3)
                max3.erase(max3.begin());
        }
        if(max3.size() < 3)
            return *max3.rbegin();
        else
            return *max3.begin();
    }
};