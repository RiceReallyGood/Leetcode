#include <vector>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int sw = 1, nsw = 0;
        for(int i = 1; i < n; i++){
            int swtemp = n, nswtemp = n;
            if(A[i] > A[i - 1] && B[i] > B[i - 1]){
                swtemp = min(swtemp, sw + 1);
                nswtemp = min(nswtemp, nsw);
            } 
            if(A[i] > B[i - 1] && B[i] > A[i - 1]){
                swtemp = min(swtemp, nsw + 1);
                nswtemp = min(nswtemp, sw);
            }
            sw = swtemp, nsw = nswtemp;
        }
        return min(sw, nsw);
    }
};