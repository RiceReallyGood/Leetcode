#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + s1[i];
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        int sum = 0;
        for(char c : s1) sum += c;
        for(char c : s2) sum += c;
        return sum - 2 * dp[len1][len2];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int> dp(len2 + 1, 0);
        vector<int> temp(len2 + 1, 0);
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(s1[i] == s2[j]) temp[j + 1] = dp[j] + s1[i];
                else temp[j + 1] = max(dp[j + 1], temp[j]);
            }
            swap(temp, dp);
        }
        int sum = 0;
        for(char c : s1) sum += c;
        for(char c : s2) sum += c;
        return sum - 2 * dp[len2];
    }
};