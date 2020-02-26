#include <iostream>
using namespace std;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        int sign, result = 0;
        if (dividend < 0)
        {
            if (dividend == INT32_MIN)
            {
                if (divisor == -1)
                    return INT32_MAX;
                if (divisor == INT32_MIN)
                    return 1;
                if (divisor == 1)
                    return INT32_MIN;
            }
            if (divisor > 0)
            {
                sign = -1;
                while (dividend <= 0)
                {
                    dividend += divisor;
                    result++;
                }
            }
            else
            {
                sign = 1;
                while (dividend <= 0)
                {
                    dividend -= divisor;
                    result++;
                }
            }
        }
        else
        {
            if (dividend == INT32_MAX)
            {
                if (divisor == 1)
                    return INT32_MAX;
            }
            if (divisor > 0)
            {
                sign = 1;
                while (dividend >= 0)
                {
                    dividend -= divisor;
                    result++;
                }
            }
            else
            {
                sign = -1;
                while (dividend >= 0)
                {
                    dividend += divisor;
                    result++;
                }
            }
        }
        result--;
        if (sign == -1)
            return -result;
        else
            return result;
    }
};