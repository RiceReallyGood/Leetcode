#include <vector>
using namespace std;

class Solution { //TLE
public:
    int findIntegers(int num) {
        vector<int> dp = {0, 1};
        int p = 1;
        while(dp.back() <= num){
            dp.push_back(dp[p] * 2);
            if(!(dp[p] & 0b1))
                dp.push_back(dp.back() + 1);
            p++;
        }
        while(dp.back() > num)
            dp.pop_back();
        return dp.size();
    }
};

class Solution {
public:
    int findIntegers(int num) {
        if(num == 0) return 1;
        int len = 0;
        int n = num;
        while(n){
           len++;
           n /= 2;
        }
        vector<int> f(len + 1);
        f[0] = 1, f[1] = 2;
        for(int i = 2; i <= len; i++)
            f[i] = f[i - 1] + f[i - 2];
        int prevbit = 0;
        int ret = 0;
        for(int i = len - 1 ; i >= 0; i--){
            if((1 << i) & num){
                ret += f[i];
                if(prevbit == 1){
                    ret--;
                    break;
                }
                else
                    prevbit = 1;
            }
            else
                prevbit = 0;
        }
        return ret + 1;
    }    
};