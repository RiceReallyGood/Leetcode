#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string Nstr = to_string(N);
        int n = D.size();
        vector<char> Dvec(n);
        for(int i = 0; i < n; i++)
            Dvec[i] = D[i][0];
        int len = Nstr.length();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        int ret = 0;
        for(int i = 1; i < len; i++){
            dp[i] = n * dp[i - 1];
            ret += dp[i];
        }

        for(int i = 0; ; i++){
            if(i == len){
                dp[len]++;
                break;
            }
            int index = lower_bound(Dvec.begin(), Dvec.end(), Nstr[i]) - Dvec.begin();
            dp[len] += index * dp[len - 1 - i];
            if(index == n || Dvec[index] != Nstr[i]) break;
        }
        ret += dp[len];
        return ret;
    }
};