#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int increase = 1, decrease = 1;
        int ret = 1;
        for(int i = 1; i < A.size(); i++){
            if(A[i] > A[i - 1]){
                increase = decrease + 1;
                decrease = 1;
                ret = max(ret, increase);
            }
            else if(A[i] < A[i - 1]){
                decrease = increase + 1;
                increase = 1;
                ret = max(ret, decrease);
            }
            else
                decrease = increase = 1;
        }
        return ret;
    }
};