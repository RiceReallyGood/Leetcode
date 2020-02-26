#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if(N == 1) return A[0][0];
        vector<int> prev = A[0];
        vector<int> curr(N, 0);
        for(int r = 1; r < N; r++){
            curr[0] = min(prev[0], prev[1]) + A[r][0];
            for(int i = 1; i < N - 1; i++)
                curr[i] = min(min(prev[i - 1], prev[i + 1]), prev[i]) + A[r][i];
            curr[N - 1] = min(prev[N - 2], prev[N - 1]) + A[r][N - 1];
            swap(curr, prev);
        }
        int ret = 100;
        for(int i = 0; i < N; i++)
            ret = min(ret, prev[i]);
        return ret;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if(N == 1) return A[0][0];
        for(int r = 1; r < N; r++){
            A[r][0] += min(A[r - 1][0], A[r - 1][1]);
            for(int i = 1; i < N - 1; i++)
                A[r][i] += min(min(A[r - 1][i - 1], A[r - 1][i]), A[r - 1][i + 1]);
            A[r][N - 1] += min(A[r - 1][N - 2], A[r - 1][N - 1]);
        }
        int ret = 100;
        for(int i = 0; i < N; i++)
            ret = min(ret, A[N - 1][i]);
        return ret;
    }
};