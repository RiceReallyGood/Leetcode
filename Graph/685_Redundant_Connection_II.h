#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> uf(N + 1), in(N + 1, 0);
        for(int i = 0; i <= N; i++)
            uf[i] = i;

        int firstcandidate = -1, secondcandidate = -1;
        for(int i = 0; i < N; i++){
            in[edges[i][1]]++;
            if(in[edges[i][1]] == 2)  secondcandidate = i;
        }
        if(secondcandidate == -1){
            for(auto& v :edges){
                if(!Union(v[0], v[1], uf))
                    return v;
            }
        }
        else{
            for(int i = 0; i < N; i++){
                if(i == secondcandidate) continue;
                if(edges[i][1] == edges[secondcandidate][1]) firstcandidate = i;
                Union(edges[i][0], edges[i][1], uf);
            }
        }
        if(root(edges[firstcandidate][0], uf) == root(edges[secondcandidate][0], uf))
            return edges[secondcandidate];
        else
            return edges[firstcandidate];
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