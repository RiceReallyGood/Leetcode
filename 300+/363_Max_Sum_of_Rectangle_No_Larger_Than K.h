#include <vector>
#include <climits>
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            int partialsum = 0;
            for(int j = 0; j < n; j++){
                partialsum += matrix[i][j];
                dp[i + 1][j + 1] = dp[i][j + 1] + partialsum;
            }
        }

        int res = INT_MIN;
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 <= j1; j2++){
                set<int> sums= {0};
                for(int i = 0; i < m; i++){
                    int sum = dp[i + 1][j1 + 1] - dp[i + 1][j2];
                    auto it = sums.lower_bound(sum - k);
                    if(it != sums.end())
                        res = max(res, sum - *it);
                    sums.insert(sum);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rowsum(m, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                rowsum[i][j + 1] = rowsum[i][j] + matrix[i][j];
        }

        int res = INT_MIN;
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 <= j1; j2++){
                int sum = 0, maxsum = INT_MIN;
                for(int i = 0; i < m; i++){
                    sum += rowsum[i][j1 + 1] - rowsum[i][j2];
                    maxsum = max(sum, maxsum);
                    if(sum < 0)
                        sum = 0;
                }
                if (maxsum <= k) {
                    res = max(res, maxsum);
                    if (res == k) return res;
                    continue;
                }
                set<int> sums;
                sums.insert(0);
                sum = 0;
                for(int i = 0; i < m; i++){
                    sum += rowsum[i][j1 + 1] - rowsum[i][j2];
                    auto it = sums.lower_bound(sum - k);
                    if(it != sums.end())
                        res = max(res, sum - *it);
                    if(res == k)
                        return k;
                    sums.insert(sum);
                }
            }
        }
        return res;
    }
};