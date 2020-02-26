class Solution {
public:
    int checkRecord(int n) {
        long dp[7] = {1, 0, 0, 0, 0, 0, 0};
        int absent = 0, notabsent = 1;
        for(int i = 1; i <= n; i++){
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = notabsent;
            dp[6] = dp[5];
            dp[5] = (dp[3] + dp[4]) % 1000000007L;
            dp[4] = absent;
            dp[3] = notabsent;
            notabsent = (dp[0] + dp[1] + dp[2]) % 1000000007L;
            absent = (dp[3] + dp[4] + dp[5] + dp[6]) % 1000000007L;
        }
        return (absent + notabsent) % 1000000007L;
    }
};