#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> board(N, vector<double>(N, 0));
        board[r][c] = 1.;
        vector<vector<vector<pair<int, int>>>> neighbours(N, vector<vector<pair<int, int>>>(N));
        for(int i = 0; i < N; i++){
            if(i >= 2){
                for(int j = 1; j < N; j++)
                    neighbours[i][j].push_back(make_pair(i - 2, j - 1));
                for(int j = 0; j < N - 1; j++)
                    neighbours[i][j].push_back(make_pair(i - 2, j + 1));
            } 
            if(i >= 1){
                for(int j = 2; j < N; j++)
                    neighbours[i][j].push_back(make_pair(i - 1, j - 2));
                for(int j = 0; j < N - 2; j++)
                    neighbours[i][j].push_back(make_pair(i - 1, j + 2));
            }
            if(i < N - 1){
                for(int j = 2; j < N; j++)
                    neighbours[i][j].push_back(make_pair(i + 1, j - 2));
                for(int j = 0; j < N - 2; j++)
                    neighbours[i][j].push_back(make_pair(i + 1, j + 2));
            }
            if(i < N - 2){
                for(int j = 1; j < N; j++)
                    neighbours[i][j].push_back(make_pair(i + 2, j - 1));
                for(int j = 0; j < N - 1; j++)
                    neighbours[i][j].push_back(make_pair(i + 2, j + 1));
            }
        }
        for(int t = 0; t < K; t++){
            vector<vector<double>> temp(N, vector<double>(N, 0));
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    for(auto& nb : neighbours[i][j])
                        temp[i][j] += board[nb.first][nb.second];
                }
            }
            swap(temp, board);
        }
        double total = pow(8., K);
        double onboard = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                onboard += board[i][j];
        return onboard / total;
    }
};