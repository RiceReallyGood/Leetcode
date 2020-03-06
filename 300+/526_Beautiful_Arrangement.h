#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        this->N = N;
        vector<set<int>> candidate(N);
        for(int i = 0; i < N; i++){
            candidate[i].insert(i + 1);
            for(int j = i + 2; j <= N; j++){
                if(j % (i + 1) == 0){
                    candidate[i].insert(j);
                    candidate[j - 1].insert(i + 1);
                }
            }
        }
        vector<bool> visited(N, false);
        int res = 0;
        recurse(visited, 0, candidate, res);
        return res;
    }

private:
    int N;
    void recurse(vector<bool>& visited, int determined, vector<set<int>>& candidate, int& res){
        if(determined == N){
            res++;
            return;
        }
        int curr = -1, currsize = N + 1;
        for(int i = 0; i < N; i++)
            if(!visited[i] && candidate[i].size() < currsize){
                curr = i;
                currsize = candidate[i].size();
            }
        
        if(currsize == 0) return;

        visited[curr] = true;
        for(auto next : candidate[curr]){
            vector<int> influenced;
            for(int i = 0; i < N; i++){
                if(!visited[i] && candidate[i].find(next) != candidate[i].end()){
                    candidate[i].erase(next);
                    influenced.push_back(i);
                }
            }
            recurse(visited, determined + 1, candidate, res);
            for(int f : influenced)
                candidate[f].insert(next);
        }
        visited[curr] = false;
    }
};

class Solution {
public:
    int countArrangement(int N) {
        this->N = N;
        vector<bool> used(N, false);
        int res = 0;
        recurse(0, used, res);
        return res;
    }

private:
    int N;
    void recurse(int determined, vector<bool>& used, int& res){
        if(determined == N) {res++; return;}
        for(int i = 0; i < N; i++){
            if(!used[i] && ((i + 1) % (determined + 1) == 0 || (determined + 1) % (i + 1) == 0)){
                used[i] = true;
                recurse(determined + 1, used, res);
                used[i] = false;
            }
        }
    }
};

class Solution {
public:
    int countArrangement(int N) {
        this->N = N;
        vector<bool> used(N, false);
        int res = 0;
        recurse(0, used, res);
        return res;
    }

private:
    int N;
    void recurse(int determined, vector<bool>& used, int& res){
        if(determined == N) {res++; return;}
        for(int i = 0; i < N; i++){
            if(!used[i] && ((i + 1) % (N - determined) == 0 || (N - determined) % (i + 1) == 0)){
                used[i] = true;
                recurse(determined + 1, used, res);
                used[i] = false;
            }
        }
    }
};

class Solution {
public:
    int countArrangement(int N) {
        vector<int> candidates(N);
        for(int i = 0; i < N; i++)
            candidates[i] = i + 1;
        return recurse(N, candidates);
    }

private:
    int recurse(int position, vector<int>& candidates){
        if(position == 0) return 1;
        int ret = 0;
        for(int i = 0; i < position; i++){
            if(candidates[i] % position == 0 || position % candidates[i] == 0){
                swap(candidates[i], candidates[position - 1]);
                ret += recurse(position - 1, candidates);
                swap(candidates[i], candidates[position - 1]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int countArrangement(int N) {
        static vector<int> res = {1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750,
                                  4010, 4237, 10680, 24679};
        return res[N - 1];
    }
};