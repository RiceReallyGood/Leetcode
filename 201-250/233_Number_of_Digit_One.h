class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        int div = 1;
        int quotient, remainder;
        int count = 0;
        while(quotient = n / div){
            remainder = n % div;
            if(quotient % 10 == 0) count += (quotient / 10) * div;
            else if(quotient % 10 == 1) count += (quotient / 10) * div + remainder + 1;
            else count += (quotient / 10 + 1) * div;
            div *= 10;
        }
        return count;
    }
};

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;  
        for (long i=1; i<=n; i *= 10)
            count += (n / i + 8) / 10 * i + ((n / i) % 10 == 1) * (n % i + 1);
        return count;
    }
};