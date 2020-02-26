#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> indices(26);
        for(int i = 0; i < ring.size(); i++)
            indices[ring[i] - 'a'].push_back(i);
        vector<int> lattersteps(n, INT_MAX);
        for(int i = 0; i < indices[key[n - 1] - 'a'].size(); i++)
            lattersteps[i] = 1;
        vector<int> currsteps(n, INT_MAX);
        for(int i = n - 2; i >= 0; --i){
            for(int idx1 = 0; idx1 < indices[key[i] - 'a'].size(); idx1++){
                for(int idx2 = 0; idx2 < indices[key[i + 1] - 'a'].size(); idx2++){
                    int step = abs(indices[key[i + 1] - 'a'][idx2] - indices[key[i] - 'a'][idx1]);
                    currsteps[idx1] = min(currsteps[idx1], lattersteps[idx2] + min(step, m - step) + 1);
                }
            }
            swap(lattersteps, currsteps);
            for(int j = 0; j < n; j++) currsteps[j] = INT_MAX;
        }
        int ret = INT_MAX;
        for(int i = 0; i < indices[key[0] - 'a'].size(); i++)
            ret = min(ret, lattersteps[i] + min(indices[key[0] - 'a'][i], m - indices[key[0] - 'a'][i]));
        return ret;
    }
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> indices(26);
        for(int i = 0; i < ring.size(); i++)
            indices[ring[i] - 'a'].push_back(i);
        vector<int> prevsteps(indices[key[0] - 'a'].size());
        for(int i = 0; i < prevsteps.size(); i++)
            prevsteps[i] = min(indices[key[0] - 'a'][i], m - indices[key[0] - 'a'][i]) + 1;
        for(int i = 1; i < n; i++){
            vector<int> currsteps(indices[key[i] - 'a'].size(), INT_MAX);
            for(int idx1 = 0; idx1 < currsteps.size(); idx1++){
                for(int idx2 = 0; idx2 < prevsteps.size(); idx2++){
                    int step = abs(indices[key[i] - 'a'][idx1] - indices[key[i - 1] - 'a'][idx2]);
                    currsteps[idx1] = min(currsteps[idx1], prevsteps[idx2] + min(step, m - step) + 1);
                }
            }
            swap(prevsteps, currsteps);
        }
        int ret = INT_MAX;
        for(int i = 0; i < prevsteps.size(); i++)
            ret = min(ret, prevsteps[i]);
        return ret;
    }
};