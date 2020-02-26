#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        if(k == 0)
            return;
        k = sz - k;
        int g = gcd (k, sz);
        for(int shift = 0; shift < g; shift++){
            int temp = nums[shift];
            int curr = shift;
            int next = (shift + k) % sz;
            while(next != shift){
                nums[curr] = nums[next];
                curr = next;
                next = (next + k) % sz;
            }
            nums[curr] = temp;
        }
    }
private:
    int gcd(int a, int b){
        while(b){
            a %= b;
            swap(a, b);
        }
        return a;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};