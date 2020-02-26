#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while(l < r){
            int c = l + (r - l) / 2;
            int count = 0;
            for(int i = 0; i <= n; i++)
                if(nums[i] <= c)
                    count++;
            if(count > c)
                r = c;
            else
                l = c + 1;
        }
        return l;
    }
};

class Solution { //这个比上边的快不知道为什么。。。。。
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while(l < r){
            int c = l + (r - l) / 2;
            int count = 0;
            for(int i = 0; i <= n; i++)
                if(l <= nums[i] && nums[i] <= c)
                    count++;
            if(count > c - l + 1)
                r = c;
            else
                l = c + 1;
        }
        return l;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};