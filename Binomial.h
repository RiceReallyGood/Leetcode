#ifndef BINOMIAL_H
#define BINOMIAL_H
#include <vector>

static std::vector<int> __Primes = {2};
static int __MaxChecked = 2;

bool __IsPrime(int n)
{
    for (int i = 0; __Primes[i] * __Primes[i] <= n; i++)
    {
        if (n % __Primes[i] == 0)
            return false;
    }
    return true;
}

void CheckPrimes(int n)
{
    if (n <= __MaxChecked)
        return;
    else
    {
        while (__MaxChecked < n)
        {
            __MaxChecked++;
            if (__IsPrime(__MaxChecked))
                __Primes.push_back(__MaxChecked);
        }
    }
}

int PrimePowofFactorial(int n, int p)
{
    int pow = 0;
    while (n >= p)
    {
        int temp = n / p;
        pow += temp;
        n = temp;
    }
    return pow;
}

int FastPow(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)
        return FastPow(x * x, n / 2);
    else
        return x * FastPow(x * x, n / 2);
}

int Binomial(int n, int k)
{
    CheckPrimes(n);
    int ret = 1;
    for (int i = 0; i < __Primes.size() && __Primes[i] <= n; i++)
    {
        int pow = PrimePowofFactorial(n, __Primes[i]) - PrimePowofFactorial(k, __Primes[i]) - PrimePowofFactorial(n - k, __Primes[i]);
        ret *= FastPow(__Primes[i], pow);
    }
    return ret;
}

#endif