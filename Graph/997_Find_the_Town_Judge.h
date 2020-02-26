#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusts(N + 1,0), trusted(N + 1, 0);
        for(auto& v : trust){
            trusts[v[0]]++;
            trusted[v[1]]++;
        }

        for(int i = 1; i <= N; i++){
            if(trusts[i] == 0 && trusted[i] == N - 1) return i;
        }
        return -1;
    }
};