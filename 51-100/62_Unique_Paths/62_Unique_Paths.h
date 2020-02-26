#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return Binomial(n + m - 2, n - 1);
    }

private:
    int Binomial(int n, int k)
    {
        CheckPrimes(n);
        int com = 1;
        for (int i = 0; i < Primes.size() && Primes[i] <= n; i++)
        {
            int pow = PrimePowofFactorial(n, Primes[i]) - PrimePowofFactorial(k, Primes[i]) - PrimePowofFactorial(n - k, Primes[i]);
            com *= FastPow(Primes[i], pow);
        }
        return com;
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