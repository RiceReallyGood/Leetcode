class Solution {
public:
    int arrangeCoins(int n) {
        long l = 1, r = long(n) + 1;
        while(l < r){
            long c = l + (r - l) / 2;
            if(c * (c + 1) / 2 <= n)
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }
};