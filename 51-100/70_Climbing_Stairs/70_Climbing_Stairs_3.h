#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        Fib.resize(n + 2, 0);
        return Fibnacci(n + 1);
    }

    int Fibnacci(int n)
    {
        if (Fib[n] != 0)
            return Fib[n];
        if (n & 1)
            return Fib[n] = Fibnacci(n / 2 + 1) * Fibnacci(n / 2 + 1) + Fibnacci(n / 2) * Fibnacci(n / 2);
        else
            return Fib[n] = (Fibnacci(n / 2 + 1) + Fibnacci(n / 2 - 1)) * Fibnacci(n / 2);
    }
    vector<int> Fib = {0, 1, 1, 2};
};