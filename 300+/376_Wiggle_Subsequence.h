#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int sz = nums.size();
        vector<int> increase(sz, 1);
        vector<int> decrease(sz, 1);
        for(int i = 0; i < sz; i++){
            for(int j = i - 1; j >= 0; --j){
                if(nums[j] == nums[i])
                    continue;
                if(nums[j] < nums[i])
                    increase[i] = max(increase[i], decrease[j] + 1);
                else
                    decrease[i] = max(decrease[i], increase[j] + 1);
            }
        }
        return max(increase[sz - 1], decrease[sz - 1]); 
        //可以证明最长的Wiggle sequence一定可以有包含最后一个元素的一种形式
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return sz;
        int i = 1;
        while(i < sz && nums[i] == nums[i - 1]) i++;
        if(i == sz)
            return 1;
        bool increase;
        if(nums[i] > nums[i - 1])
            increase = true;
        else
            increase = false;
        int prevnum = nums[i];
        int count = 2;
        for(i++; i < sz; i++){
            if((nums[i] > prevnum && !increase) || (nums[i] < prevnum && increase)){
                increase = !increase;
                count++;
            }
            prevnum = nums[i];
        }
        return count;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return sz;
        int diff = nums[1] - nums[0];
        int count = diff == 0 ? 1 :2;
        int prevdiff = diff;
        for(int i = 2; i < sz; i++){
            diff = nums[i] - nums[i - 1];
            if((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)){
                count ++;
                prevdiff = diff;
            }
        }
        return count;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int sz = nums.size();
        int up = 1, down = 1;
        for(int i = 1; i < sz; i++){
            if(nums[i] > nums[i - 1])
                up = down + 1;
            if(nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};