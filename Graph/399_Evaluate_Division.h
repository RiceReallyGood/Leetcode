#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> vset;
        for(auto& v : equations){
            vset.insert(v[0]);
            vset.insert(v[1]);
        }
        vector<string> variables(vset.begin(), vset.end());
        int numVariables = variables.size();
        unordered_map<string, int> order;
        for(int i = 0; i < numVariables; i++)
            order[variables[i]] = i;
        vector<int> uf(numVariables);
        vector<double> multi(numVariables);
        for(int i = 0; i < variables.size(); i++){
            uf[i] = i;
            multi[i] = 1.;
        }

        for(int i = 0; i < equations.size(); i++){
            uf[order[equations[i][0]]] = uf[order[equations[i][1]]];
            multi[order[equations[i][0]]] = multi[order[equations[i][1]]] * values[i];
        }

        vector<double> ret;
        for(int i = 0; i < queries.size(); i++){
            if(order.find(           queries[i][0]) == order.end() || 
                          order.find(queries[i][1]) == order.end() ||
                         !connect(order[queries[i][0]], order[queries[i][1]], uf, multi))
            {
                ret.push_back(-1);
            }
            else{
                ret.push_back(multi[order[queries[i][0]]] / multi[order[queries[i][1]]]);
            }
        }
        return ret;
    }

private:
    bool connect(int a, int b, vector<int>& uf, vector<double>& multi){
        pathcomp(a, uf, multi);
        pathcomp(b, uf, multi);
        return uf[a] == uf[b];

    }

    void pathcomp(int a, vector<int>& uf, vector<double>& multi){
        if(uf[a] == a) return;
        pathcomp(uf[a], uf, multi);
        multi[a] *= multi[uf[a]];
        uf[a] = uf[uf[a]];
    }
};