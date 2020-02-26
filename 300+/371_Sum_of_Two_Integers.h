class Solution {
public:
    int getSum(int a, int b) {
        unsigned ua = static_cast<unsigned>(a), ub = static_cast<unsigned>(b);
        unsigned rest;
        while(ub){
            rest = ua & ub;
            ua ^= ub;
            ub = rest << 1;
        }
        return static_cast<int>(ua);
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0){
            int add = a ^ b;
            int carry = (a & b & 0x7fffffff) << 1;
            a = add;
            b = carry;
            
        }
        return a;
        
    }
};