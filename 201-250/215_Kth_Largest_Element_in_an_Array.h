#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

private:
    int findKthLargest(vector<int>& nums, int b, int e, int k){
        int c = b + (e - b) / 2;
        if(nums[b] < nums[e]){
            if(nums[c] < nums[b])
                swap(nums[b], nums[e]);
            else if(nums[c] < nums[e])
                swap(nums[c], nums[e]);
        }
        else{
            if(nums[c] > nums[b])
                swap(nums[b], nums[e]);
            else if(nums[c] > nums[e])
                swap(nums[c], nums[e]);
        }
        int pivot = nums[e];
        int i = b, j = e - 1;
        while(i <= j){
            if(nums[i] < pivot)
                i++;
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        swap(nums[i], nums[e]);
        if(e - i == k - 1)
            return nums[i];
        if(e - i > k - 1)
            return findKthLargest(nums, i + 1, e, k);
        else
            return findKthLargest(nums, b, j, k - (e - j));
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

private:
    int findKthLargest(vector<int>& nums, int b, int e, int k){
        int rand_idx = rand() % (e - b + 1) + b;
        swap(nums[rand_idx], nums[e]);
        int i = b, j = e - 1;
        while(i <= j){
            if(nums[i] < nums[e])
                i++;
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        swap(nums[i], nums[e]);
        if(e - i == k - 1)
            return nums[i];
        if(e - i > k - 1)
            return findKthLargest(nums, i + 1, e, k);
        else
            return findKthLargest(nums, b, j, k - (e - j));
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> h(nums.begin(), nums.end());
        for(int i = 0; i < k - 1; i++)
            h.pop();
        return h.top();
    }
};