#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> uf(26);
        for(int i = 0; i < 26; i++) uf[i] = i;
        for(auto& s : equations){
            if(s[1] == '=')
                Union(s[0] - 'a', s[3] - 'a', uf);
        }

        for(auto& s : equations){
            if(s[1] == '!'){
                if(isconnect(s[0] - 'a', s[3] - 'a', uf))
                    return false;
            }
        }
        return true;
    }

private:
    int root(int v, vector<int>& uf){
        /* if(uf[v] != v) uf[v] = root(uf[v], uf);
        return uf[v]; */
        while(v != uf[v]){
            uf[v] = uf[uf[v]];
            v = uf[v];
        }
        return v;
    }

    void Union(int v1, int v2, vector<int>& uf){
        int root1 = root(v1, uf);
        int root2 = root(v2, uf);
        uf[root1] = root2;
    }

    bool isconnect(int v1, int v2, vector<int>& uf){
        return root(v1, uf) == root(v2, uf);
    }
};