class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int divisorsum = 1;
        int divisor = 2;
        for(; divisor * divisor < num; divisor++)
            if(num % divisor == 0) divisorsum += num / divisor + divisor;
        if(divisor * divisor == num)
            divisorsum += divisor;
        return num == divisorsum;
    }
};