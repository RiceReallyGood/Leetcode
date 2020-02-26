class Solution {
public:
    bool isPowerOfFour(int num) {
        int mask = 0b10101010101010101010101010101010;
        if(num <= 0 || num & mask)
            return false;
        return (num & (num - 1)) == 0;
    }
};