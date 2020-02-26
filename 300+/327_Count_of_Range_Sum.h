#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> psums = {0};
        int count = 0;
        long psum = 0;
        for(int i = 0; i < nums.size(); i++){
            psum += nums[i];
            count += distance(psums.lower_bound(psum - upper), psums.upper_bound(psum - lower));
            psums.insert(psum);
        }
        return count;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        low = lower;
        up = upper;
        if(nums.empty())
            return 0;
        int sz = nums.size();
        vector<long> psum(sz);
        vector<long> temp(sz);
        psum[0] = nums[0];
        for(int i = 1; i < sz; i++)
            psum[i] = psum[i - 1] + nums[i];
        int count = 0;
        merge(psum, temp, 0, sz - 1, count);
        return count;
    }

private:
    int low, up;
    void merge(vector<long>& psum, vector<long>& temp,int l, int r, int& count){
        if(l == r){
            if(psum[l] <= up && psum[l] >= low) count++;
            return;
        }
        int c = l + (r - l) / 2;
        merge(psum, temp, l, c, count);
        merge(psum, temp, c + 1, r, count);
        int lb = l, ub = l;
        for(int i = c + 1; i <= r; i++){
            while(lb <= c && psum[i] - psum[lb] > up) ++lb;
            while(ub <= c && psum[i] - psum[ub] >= low) ++ub;
            count += ub - lb;
        }
        //merge sort
        int i = l, j = c + 1, k = l;
        while(i <= c || j <= r){
            if(j > r || (i <= c && psum[i] <= psum[j]))
                temp[k++] = psum[i++];
            else
                temp[k++] = psum[j++];
        }
        for(i = l; i <= r; i++)
            psum[i] = temp[i];
    }
};