#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        UF uf(2 * N * ( N + 1));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int up = i * (2 * N + 1) + j;
                int left = up + N;
                int right = left + 1;
                int down = up + 2 * N + 1;
                if(grid[i][j] == '\\'){
                    uf.Union(up, right);
                    uf.Union(left, down);
                }
                else if(grid[i][j] == '/'){
                    uf.Union(up, left);
                    uf.Union(right, down);
                }
                else{
                    uf.Union(up, right);
                    uf.Union(left, down);
                    uf.Union(up, left);
                }
            }
        }
        return uf.size();
    }

private:
    class UF{
    public:
        UF(int n) : parent(n), sz(n){ for(int i = 0; i < n; i++) parent[i] = i; }
        int size(){ return sz; }
        int root(int v){
            if(parent[v] != v) parent[v] = root(parent[v]);
            return parent[v];
        }
        void Union(int v1, int v2){
            int root1 = root(v1);
            int root2 = root(v2);
            if(root1 != root2){
                parent[root2] = root1;
                sz--;
            }
        }
    private:
        int sz;
        vector<int> parent;
    };
};