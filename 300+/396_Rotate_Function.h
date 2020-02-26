#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // F[k] = F[k - 1] + Sum(A) - n * A[n - k];
        long sum = 0;
        int n = A.size();
        for(int i = 0; i < n; i++)
            sum += A[i];
        long F = 0;
        for(int i = 0; i < n; i++)
            F += i * A[i];
        long maxF = F;
        for(int i = 1; i < n; i++){
            F = F + sum - long(n) * long(A[n - i]);
            if(F > maxF)
                maxF = F;
        }
        return maxF;
    }
};