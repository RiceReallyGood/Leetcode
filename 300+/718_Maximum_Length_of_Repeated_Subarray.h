#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int maxlen = 0;
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(A[i] == B[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    maxlen = max(maxlen, dp[i + 1][j + 1]);
                }
                else dp[i + 1][j + 1] = 0;
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size();
        int len2 = B.size();
        vector<int> dp(len2 + 1, 0);
        int maxlen = 0;
        for(int i = 0; i < len1; i++){
            for(int j = len2 - 1; j >= 0; j--){
                if(A[i] == B[j]){
                    dp[j + 1] = dp[j] + 1;
                    maxlen = max(maxlen, dp[j + 1]);
                }
                else dp[j + 1] = 0;
            }
        }
        return maxlen;
    }
};