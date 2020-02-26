#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> V1 = Str2Vec(version1);
        vector<int> V2 = Str2Vec(version2);
        for(int i = 0; i < V1.size() || i < V2.size(); i++){
            if(i >= V1.size()){
                if(V2[i] != 0)
                    return -1;
                continue;
            }
                
            if(i >= V2.size()){
                if(V1[i] != 0)
                    return 1;
                continue;
            }

            if(V1[i] < V2[i])
                return -1;
            else if(V1[i] > V2[i])
                return 1;
        }
        return 0;
    }

private:
    vector<int> Str2Vec(string &v){
        int b = 0, e =0;
        vector<int> ret;
        while(e < v.size()){
            while(e < v.size() && v[e] != '.')
                e++;
            ret.push_back(stoi(v.substr(b, e - b)));
            e++;
            b = e;
        }
        return ret;
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        for (int i = 0, j = 0; i < m || j < n;) {
            int v1 = getVersion(version1, i);
            int v2 = getVersion(version2, j);
            if (v1 > v2)
                return 1;
            if (v1 < v2)
                return -1;
        }
        return 0;
    }
    
    int getVersion(const string &s, int &i) {
        if (i >= s.size())
            return 0;
        int ret = 0;
        for (; i < s.size() && s[i] != '.'; ++i)
            ret = 10 * ret + s[i] - '0';
        ++i;
        return ret;
    }
};