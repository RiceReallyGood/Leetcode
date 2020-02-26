#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        CheckPrimes(2 * n);
        int ret = 1;
        for (int i = 0; i < Primes.size() && Primes[i] <= 2 * n; i++)
        {
            int pow = PrimePowofFactorial(2 * n, Primes[i]) - PrimePowofFactorial(n, Primes[i]) - PrimePowofFactorial(n + 1, Primes[i]);
            ret *= FastPow(Primes[i], pow);
        }
        return ret;
    }

private:
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

    bool IsPrime(int n)
    {
        for (int i = 0; Primes[i] * Primes[i] <= n; i++)
        {
            if (n % Primes[i] == 0)
                return false;
        }
        return true;
    }

    void CheckPrimes(int n)
    {
        if (n <= MaxChecked)
            return;
        else
        {
            while (MaxChecked < n)
            {
                MaxChecked++;
                if (IsPrime(MaxChecked))
                    Primes.push_back(MaxChecked);
            }
        }
    }
    vector<int> Primes = {2};
    int MaxChecked = 2;
};