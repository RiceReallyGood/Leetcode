#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevMax = 0;
        int res = minNum;

        for (int num : nums) {
            prevMax = max(num, prevMax + num);
            res = max(res, prevMax);
        }

        return res;
    }

private:
    static constexpr int minNum = -10001;
};