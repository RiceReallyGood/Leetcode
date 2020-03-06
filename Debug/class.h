#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        this->N = N;
        vector<int> candidates(N);
        for(int i = 0; i < N; i++)
            candidates[i] = i + 1;
        int res = 0;
        recurse(0, candidates, res);
        return res;
    }

private:
    int N;
    void recurse(int determined, vector<int>& candidates, int& res){
        if(determined == N) {res++; return;}
        for(int i = 0; i < N - determined; i++){
            if(candidates[i] % (N - determined) == 0 || (N- determined) % candidates[i] == 0){
                swap(candidates[i], candidates[N - determined - 1]);
                recurse(determined + 1, candidates, res);
                swap(candidates[i], candidates[N - determined - 1]);
            }
        }
    }
};