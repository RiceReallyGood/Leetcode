#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UF uf(N);
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++)
                if(M[i][j] == 1) uf.Union(i, j);
        }
        return uf.size();
    }

private:
    class UF{
    public:
        UF(int n) : parent(n), rank(n){
            sz = n;
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        void Union(int v1, int v2){
            int root1 = root(v1);
            int root2 = root(v2);
            if(root1 == root2) return;
            if(rank[root1] > rank[root2])
                parent[root2] = root1;
            else if(rank[root1] < rank[root2])
                parent[root1] = root2;
            else{
                parent[root2] = root1;
                rank[root1]++;
            }
            sz--;
        }

        int size() {return sz;}
    
    private:
        int root(int v){
            if(parent[v] != v) parent[v] = root(parent[v]);
            return parent[v];
        }
        vector<int> parent;
        vector<int> rank;
        int sz;
    };
};