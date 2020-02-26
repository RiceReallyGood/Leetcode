#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int ret = 0;
        int increasement = A[1] - A[0];
        int count  = 1;
        for(int i = 2; i < A.size(); i++){
            int newincreasement = A[i] - A[i -1];
            if(newincreasement == increasement) count++;
            else{
                if(count > 1)
                    ret += count * (count - 1) / 2;
                count = 1;
                increasement = newincreasement;
            }
        }
        if(count > 1)
            ret += count * (count - 1) / 2;
        return ret;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        int ret = 0;
        int increasement = A[1] - A[0];
        int dp = 0;
        for(int i = 2; i < A.size(); i++){
            int newincreasement = A[i] - A[i -1];
            if(newincreasement == increasement){
                dp++;
                ret += dp;
            }
            else{
                dp = 0;
                increasement = newincreasement;
            }
        }
        return ret;
    }
};