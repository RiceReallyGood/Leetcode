#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        sort(A.begin(), A.end());
        A.resize(distance(A.begin(), unique(A.begin(), A.end())));
        int N = A.size();
        vector<int> uf(N);
        int sz = N;
        for(int i = 0; i < N; i++) uf[i] = i;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                if(root(i, uf) == root(j, uf)) continue;
                if(isSimilar(A[j], A[i])){
                    Union(i, j, uf);
                    sz--;
                }
            }
        }
        return sz;
    }

private:
    bool isSimilar(const string& s1, const string& s2){
        int diffcount = 0;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i] && (++diffcount) > 2) return false;
        return true;
    }

    int root(int v, vector<int>& uf){ //发现递归的会更慢
        /* if(uf[v] != v) uf[v] = root(uf[v], uf);
        return uf[v]; */
        while(uf[v] != v){
            uf[v] = uf[uf[v]];
            v = uf[v];
        }
        return v;
    }

    void Union(int v1, int v2, vector<int>& uf){
        int root1 = root(v1, uf);
        int root2 = root(v2, uf);
        uf[root2] = root1;
    }
};