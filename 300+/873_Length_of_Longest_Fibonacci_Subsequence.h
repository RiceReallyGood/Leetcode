#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++)
            index[A[i]] = i;
            
        int ret = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                int target = A[i] - A[j];
                if(target >= A[j]) break;
                if(index.find(target) != index.end()){
                    dp[j][i] = max(dp[j][i], dp[index[target]][j] + 1);
                    ret = max(ret, dp[j][i]);
                }
            }
        }
        return ret > 2 ? ret : 0;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_set<int> nums(A.begin(), A.end());
        int ret = 2;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double num1 = A[i], num2 = A[j];
                if(num2 * (ret - 2) >= A.back()) break;
                int count = 2;
                double target = num1 + num2;
                while(nums.find(target) != nums.end()){
                    count++;
                    num1 = num2;
                    num2 = target;
                    target = num1 + num2;
                }
                ret = max(ret, count);
            }
            
        }
        return ret > 2 ? ret : 0;
    }
};