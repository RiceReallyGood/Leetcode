#include <vector>
using namespace std;

class NumArray1 {
public:
    NumArray1(vector<int>& nums) : nums_(nums), indexTree(nums.size() + 1) {
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            indexTree[i] = sum - sumPrefix(i & (i - 1));
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums_[index];
        nums_[index] = val;
        
        index = index + 1;
        while (index <= nums_.size()) {
            indexTree[index] += delta;
            index += index & (-index);
        }
    }
    
    int sumRange(int left, int right) {
        int l = sumPrefix(left);
        int r = sumPrefix(right + 1);
        return r - l;
    }

private:
    int sumPrefix(int n) {
        int sum = 0;
        while (n) {
            sum += indexTree[n];
            n = n & (n - 1);
        }
        return sum;
    }

    vector<int> indexTree;
    vector<int> nums_;
};

class NumArray {
public:
    NumArray(vector<int>& nums) : nums_(nums), indexTree(nums.size()) {
        if (nums.size() < 0) return;
        indexTree[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            indexTree[i] = sum - sumPrefix(i & (i - 1));
        }
    }
    
    void update(int index, int val) {
        if (index == 0) {
            indexTree[0] = val;
            nums_[0] = val;
            return;
        }

        int delta = val - nums_[index];
        nums_[index] = val;
        while (index < nums_.size()) {
            indexTree[index] += delta;
            index = index + (index & (-index));
        }
    }
    
    int sumRange(int left, int right) {
        return sumPrefix(right) - sumPrefix(left - 1);
    }

private:
    int sumPrefix(int n) {
        if (n < 0) return 0;
        if (n == 0) return indexTree[0];
        int sum = indexTree[0];
        while (n) {
            sum += indexTree[n];
            n = n & (n - 1);
        }
        return sum;
    }

    vector<int> indexTree;
    vector<int> nums_;
};

//[-28,-39,53,65,11,-56,-65,-39,-43,97]
//-28,-67,-14,51,62,6,-59