#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        if(N == 1) return 10;
        int mod = 1e9 + 7;
        vector<int> dp(4, 1);
        vector<int> temp(4, 0);
        //dp[0] 以 0 结尾
        //dp[1] 以 角落的数字(1, 3, 7, 9)结尾
        //dp[2] 以 行中间的数字(2, 8)结尾
        //dp[3] 以 列中间的数字(4, 6)结尾
        //5 无法从其他的数字到达， 所以长度大于 1 的号码不需要考虑 5
        for(int i = 1; i < N; i++){
            temp[0] = 2 * dp[3] % mod;
            temp[1] = (dp[2] + dp[3]) % mod;
            temp[2] = 2 * dp[1] % mod;
            temp[3] = (dp[0] + temp[2]) % mod;
            swap(temp, dp);
        }
        long ret = (long(dp[0]) + 4 * long(dp[1]) + 2 * long(dp[2]) + 2 * long(dp[3])) % mod;
        return ret;
    }
};

class Solution {
public:
    int knightDialer(int N) { //试验 加法是否比乘法快很多： 否
        if(N == 1) return 10;
        int mod = 1e9 + 7;
        vector<int> dp(4, 1);
        vector<int> temp(4, 0);
        for(int i = 1; i < N; i++){
            temp[0] = (dp[3] + dp[3]) % mod;
            temp[1] = (dp[2] + dp[3]) % mod;
            temp[2] = (dp[1] + dp[1]) % mod;
            temp[3] = (dp[0] + temp[2]) % mod;
            swap(temp, dp);
        }
        long ret = (long(dp[0]) + 4 * long(dp[1]) + 2 * long(dp[2]) + 2 * long(dp[3])) % mod;
        return ret;
    }
};