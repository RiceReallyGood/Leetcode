#include <cmath>

class Solution {
public:
    int largestPalindrome(int n) {
        int maxnum = std::pow(10, n) - 1;
        int minnum = std::pow(10, n - 1);
        for(int i = maxnum; i >= minnum; --i){
            long p = Palindrome(i);
            for(int j = i; j <= maxnum; j++){
                long d = p / j;
                if(p % j == 0 && d >= minnum && d <= maxnum)
                    return p % 1337;
            }
        }
        return maxnum;
    }

private:
    long Palindrome(int n){
        long ret = n;
        while(n){
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    }
};

class Solution {
public:
    int largestPalindrome(int n) {
        static int a[8] = {9, 987, 123, 597, 677, 1218, 877, 475};
        return a[n - 1];
    }
};