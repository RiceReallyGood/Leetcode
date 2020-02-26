#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
        {
            if (n == INT32_MIN)
                return 1. / myPow(x * x, 1 << 30);
            return 1. / myPow(x, -n);
        }
        if (n % 2 == 1)
            return x * myPow(x * x, n / 2);
        else
            return myPow(x * x, n / 2);
    }
};