#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        if(S.empty()) return 0;
        int N = S.length();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        dp[0][0] = 1;
        for(int i = 0; i < N; i++){
            if(S[i] == 'I'){
                int sum = 0;
                for(int j = 0; j <= i; j++){
                    dp[i + 1][j] = sum;
                    sum += dp[i][j];
                }
                dp[i + 1][i + 1] = sum;
            }
            else{
                int sum = 0;
                for(int j = i + 1; j > 0; j--){
                    dp[i + 1][j] = sum;
                    sum += dp[i][j - 1];
                }
                dp[i + 1][0] = sum;
            }
        }
        int ret = 0;
        for(int i = 0; i <= N; i++)
            ret += dp[N][i];
        return ret;
    }
};

class Solution {
public:
    int numPermsDISequence(string S) {
        if(S.empty()) return 0;
        int N = S.length();
        vector<int> dp(N + 1);
        dp[0] = 1;
        for(int i = 0; i < N; i++){
            if(S[i] == 'I'){
                int sum = 0;
                for(int j = 0; j <= i; j++){
                    int temp = dp[j];
                    dp[j] = sum;
                    sum = (sum + temp) % 1000000007L;
                }
                dp[i + 1] = sum;
            }
            else{
                int sum = 0;
                for(int j = i + 1; j > 0; j--){
                    dp[j] = sum;
                    sum = (sum + dp[j - 1]) % 1000000007L;
                }
                dp[0] = sum;
            }
        }
        int ret = 0;
        for(int i = 0; i <= N; i++)
            ret = (ret + dp[i]) % 1000000007L;
        return ret;
    }
};