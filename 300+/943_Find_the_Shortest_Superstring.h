#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> ol(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ol[i][j] = overlap(A[i], A[j]);
        vector<vector<int>> dp(1 << n, vector<int>(n));
        for(int mask = 1; mask < dp.size(); mask++){
            for(int i = 0; i < n; i++){
                if(((mask >> i) & 1) == 1) continue;
                for(int j = 0; j < n; j++){
                    if(((mask >> j) & 1) == 0) continue;
                    dp[mask | (1 << i)][i] = max(dp[mask | (1 << i)][i], dp[mask][j] + ol[j][i]);
                }
            }
        }
        vector<int> indices = {0};
        int mask = (1 << n) - 1;
        for(int i = 0; i < n; i++)
            if(dp[mask][i] > dp[mask][indices[0]])
                indices[0] = i;
        mask ^= (1 << indices[0]);
        while(mask){
            for(int i = 0; i < n; i++)
                if(((mask >> i) & 1) == 1 && dp[mask][i] + ol[i][indices.back()] == dp[mask | (1 << indices.back())][indices.back()]){
                    indices.push_back(i);
                    break;
                }
            mask ^= (1 << indices.back());
        }


        int previndex = indices.back();
        string ret(A[previndex]);
        indices.pop_back();
        while(!indices.empty()){
            int index = indices.back();
            ret += A[index].substr(ol[previndex][index]);
            previndex = index;
            indices.pop_back();
        }
        return ret;
    }

private:
    int overlap(const string& s1, const string& s2){
        int bound = min(s1.length(), s2.length());
        for(int len = bound; len > 0; len--){
            int i = s1.length() - 1, j = len - 1;
            while(j >= 0 && s1[i] == s2[j]){
                i--;
                j--;
            }
            if(j == -1) return len;
        }
        return 0;
    }
};