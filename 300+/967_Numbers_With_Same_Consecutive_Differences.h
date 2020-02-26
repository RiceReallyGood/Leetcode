#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) return {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int len = 2; len <= N; len++){
            vector<int> temp;
            for(int num : nums){
                int lastdigit = num % 10;
                if(lastdigit + K < 10)
                    temp.push_back(num * 10 + lastdigit + K);
                if(lastdigit >= K && K != 0)
                    temp.push_back(num * 10 + lastdigit - K);
            }
            swap(temp, nums);
        }
        return nums;
    }
};