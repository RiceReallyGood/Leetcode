#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if(N == 0) return 0;
        vector<vector<int>> board(N, vector<int>(N, 1));
        for(auto& v : mines) board[v[0]][v[1]] = 0;
        vector<vector<int>> order(N, vector<int>(N, 0));
        vector<int> dp1(N), dp2(N);
        for(int i = 0; i < N; i++){
            dp1[0] = board[i][0];
            for(int j = 1; j < N; j++)
                dp1[j] = board[i][j] == 0 ? 0 : dp1[j - 1] + 1;
            dp2[N - 1] = board[i][N - 1];
            for(int j = N - 2; j >= 0; j--)
                dp2[j] = board[i][j] == 0 ? 0 : dp2[j + 1] + 1;
            for(int j = 0; j < N; j++)
                order[i][j] = min(dp1[j], dp2[j]);
        }

        for(int j = 0; j < N; j++){
            dp1[0] = board[0][j];
            for(int i = 1; i < N; i++)
                dp1[i] = board[i][j] == 0 ? 0 : dp1[i - 1] + 1;
            dp2[N - 1] = board[N - 1][j];
            for(int i = N - 2; i >= 0; i--)
                dp2[i] = board[i][j] == 0 ? 0 : dp2[i + 1] + 1;
            for(int i = 0; i < N; i++)
                order[i][j] = min(order[i][j], min(dp1[i], dp2[i]));
        }
        int ret = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ret = max(ret, order[i][j]);
        return ret;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if(N == 0) return 0;
        vector<vector<int>> board(N, vector<int>(N, 1));
        for(auto& v : mines) board[v[0]][v[1]] = 0;
        vector<vector<int>> order(N, vector<int>(N, N));
        int ret = 0;
        for(int i = 0; i < N; i++){
            int count = 0;
            for(int j = 0; j < N; j++){
                count = board[i][j] == 0 ? 0 : count + 1;
                order[i][j] = min(order[i][j], count);
            }
            count = 0;
            for(int j = N - 1; j >= 0; j--){
                count = board[i][j] == 0 ? 0 : count + 1;
                order[i][j] = min(order[i][j], count);
            }
        }

        for(int j = 0; j < N; j++){
            int count = 0;
            for(int i = 0; i < N; i++){
                count = board[i][j] == 0 ? 0 : count + 1;
                order[i][j] = min(order[i][j], count);
            }
            count = 0;
            for(int i = N - 1; i >= 0; i--){
                count = board[i][j] == 0 ? 0 : count + 1;
                order[i][j] = min(order[i][j], count);
                ret = max(ret, order[i][j]);
            }
        }
        return ret;
    }
};