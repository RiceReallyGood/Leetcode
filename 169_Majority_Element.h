#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = 0, mecount = 0;
        for (int num : nums) {
            if (num == me) {
                ++mecount;
            } else {
                if (mecount == 0) {
                    me = num;
                    mecount = 1;
                } else {
                    --mecount;
                }
            }
        }
        return me;
    }
};