#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> larger(n + 1, n);
        vector<int> smaller(n + 1, n);
        map<int, int> smallestindex;
        for(int i = n - 1; i >= 0; i--){
            auto it = smallestindex.lower_bound(A[i]);
            if(it != smallestindex.end())
                larger[i] = (*it).second;

            if(it != smallestindex.end() && (*it).first == A[i])
                smaller[i] = (*it).second;
            else if(it != smallestindex.begin())
                smaller[i] = (*(--it)).second;
            
            smallestindex[A[i]] = i;
        }
        larger[n - 1] = smaller[n - 1] = n - 1;

        vector<bool> dp(n + 1, false);
        dp[n - 1] = true;

        int ret = 1;
        for(int i = n - 2; i >= 0; i--){
            if(dp[smaller[larger[i]]]){
                dp[i] = true;
                ret++;
            }
        }
        return ret;
    }
};