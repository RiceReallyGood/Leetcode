#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> neighbours(n);
        for(auto& v : edges){
            neighbours[v[0]].insert(v[1]);
            neighbours[v[1]].insert(v[0]);
        }
        unordered_set<int> left;
        for(int i = 0; i < n; i++)
            left.insert(i);
        
        while(left.size() > 2){
            vector<int> leaves;
            for(int node : left){
                if(neighbours[node].size() == 1)
                    leaves.push_back(node);
            }
            for(int node : leaves){
                left.erase(node);
                neighbours[*(neighbours[node].begin())].erase(node);
            }
        }

        return vector<int>(left.begin(), left.end());
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> neighbours(n);
        for(auto& v : edges){
            neighbours[v[0]].insert(v[1]);
            neighbours[v[1]].insert(v[0]);
        }
        
        vector<int> currlevel, nextlevel;
        for(int i = 0; i < n; i++)
            if(neighbours[i].size() == 1)
                nextlevel.push_back(i);

        int left = n;       
        while(left > 2){
            swap(currlevel, nextlevel);
            nextlevel.clear();
            for(int node : currlevel){
                int nb =  *(neighbours[node].begin());
                neighbours[nb].erase(node);
                if(neighbours[nb].size() == 1)
                    nextlevel.push_back(nb);
            }
            left -= currlevel.size();
        }
        return nextlevel;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> nbcount(n, 0);
        vector<int> nbsum(n, 0);
        for(auto& v : edges){
            nbcount[v[0]]++;
            nbcount[v[1]]++;
            nbsum[v[0]] += v[1];
            nbsum[v[1]] += v[0];
        }

        vector<int> next;
        for(int i = 0; i < n; i++)
            if(nbcount[i] == 1)
                next.push_back(i);
        
        int beg = 0, end = next.size();
        while(next.size() < n){
            for(int i = beg; i < end; i++){
                int nb = nbsum[next[i]];
                nbcount[nb]--;
                nbsum[nb] -= next[i];
                if(nbcount[nb] == 1)
                    next.push_back(nb);
            }
            beg = end;
            end = next.size();
        }
        return vector<int>(next.begin() + beg, next.end());
    }
};