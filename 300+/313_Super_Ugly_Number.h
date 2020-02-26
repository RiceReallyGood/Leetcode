#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> SUN(n, 1);
        vector<int> p(primes.size(), 0);
        vector<int> next(primes);
        for(int i = 1; i < n; i++){
            int minnext = *min_element(next.begin(), next.end());
            SUN[i] = minnext;
            for(int j = 0; j < primes.size(); j++)
                if(next[j] == minnext)  next[j] = SUN[++p[j]] * primes[j];
        }
        return SUN[n - 1];
    }
};