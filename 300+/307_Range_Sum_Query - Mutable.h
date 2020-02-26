#include <vector>
using namespace std;

class NumArray { //Binary Index Tree
public:
    NumArray(vector<int>& nums) :data(nums){
        len = nums.size() + 1;
        BIT.resize(len);
        for(int i = 0; i < nums.size(); i++)
            add(i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        add(i + 1, val - data[i]);
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }

    int lowbit(int pos) { return pos & (-pos); };

    void add(int pos, int val){
        while(pos < len){
            BIT[pos] += val;
            pos += lowbit(pos);
        }
    }

    int query(int pos){
        int ret = 0;
        while(pos){
            ret += BIT[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }

private:
    int len;
    vector<int> BIT;
    vector<int> data;
};