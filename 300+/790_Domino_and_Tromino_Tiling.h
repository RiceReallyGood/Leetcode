#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        if(N == 2) return 2;
        vector<long> up(N + 1), eq(N + 1), down(N + 1);
        up[0] = up[1] = down[0] = down[1] = 0;
        up[2] = down[2] = 1;
        eq[0] = 0;
        eq[1] = 1;
        eq[2] = 2;
        for(int i = 3; i <= N; i++){
            up[i] = (down[i - 1] + eq[i - 2]) % 1000000007L;
            down[i] = (up[i - 1] + eq[i - 2]) % 1000000007L;
            eq[i] = (eq[i - 1] + eq[i - 2] + up[i - 1] + down[i - 1]) % 1000000007L;
        }
        return eq[N] % 1000000007L;
    }
};

class Solution {
public:
    int numTilings(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        if(N == 2) return 2;
        vector<long> eq(N + 1), neq(N + 1);
        neq[0] = neq[1] = 0, neq[2] = 1;
        eq[0] = 0, eq[1] = 1, eq[2] = 2; 
        for(int i = 3; i <= N; i++){
            neq[i] = (neq[i - 1] + eq[i - 2]) % 1000000007L;
            eq[i] = (eq[i - 1] + eq[i - 2] + neq[i - 1] + neq[i - 1]) % 1000000007L;
        }
        return eq[N] % 1000000007L;
    }
};