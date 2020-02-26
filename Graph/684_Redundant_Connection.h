#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> uf(N + 1);
        for(int i = 0; i <= N; i++)
            uf[i] = i;

        for(auto& v :edges){
            int rootv0 = v[0];
            while(uf[rootv0] != rootv0){
                uf[rootv0] = uf[uf[rootv0]];
                rootv0 = uf[rootv0];
            }
            int rootv1 = v[1];
            while(uf[rootv1 ] != rootv1 ){
                uf[rootv1] = uf[uf[rootv1]];
                rootv1  = uf[rootv1];
            }
            if(rootv0 != rootv1)
                uf[rootv1] = rootv0;
            else
                return v;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> uf(N + 1);
        for(int i = 0; i <= N; i++)
            uf[i] = i;

        for(auto& v :edges){
            if(!Union(v[0], v[1], uf))
                return v;
        }
        return {};
    }

private:
    int root(int e, vector<int>& uf){
        if(uf[e] != e) uf[e] = root(uf[e], uf);
        return uf[e];
    }
    bool Union(int e1, int e2, vector<int>& uf){
        int roote1 = root(e1, uf);
        int roote2 = root(e2, uf);
        if(roote1 == roote2) return false;
        uf[roote2] = uf[roote1];
        return true;
    }
};