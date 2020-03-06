#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution(int n_rows, int n_cols) : n (n_rows), m(n_cols), sites(n_rows * n_cols), board(n_rows * n_cols, 0) {
        for(int i = 0; i < sites; i++) board[i] = i;
    }
    
    vector<int> flip() {
        int r = rand() % sites;
        sites--;
        swap(board[r], board[sites]);
        return {board[sites] / m, board[sites] % m};
    }
    
    void reset() { sites = n * m; }

private:
    vector<int> board;
    int n, m;
    int sites;
};

class Solution {
public:
    Solution(int n_rows, int n_cols) : n (n_rows), m(n_cols), sites(n_rows * n_cols) {}
    
    vector<int> flip() {
        int r = rand() % sites;
        sites--;
        int ret = board.find(r) == board.end() ? r : board[r];
        board[r] = board.find(sites) == board.end() ? sites : board[sites]; 
        return {ret / m, ret % m};
    }
    
    void reset() { 
        board.clear();
        sites = n * m; 
    }

private:
    unordered_map<int, int> board;
    int n, m;
    int sites;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */