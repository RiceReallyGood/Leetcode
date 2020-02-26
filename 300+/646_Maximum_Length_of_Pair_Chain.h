#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), 
            [](vector<int>& v1, vector<int>& v2){
                return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
            }
        );
        vector<int> s;
        s.push_back(pairs[0][1]);
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] == pairs[i - 1][0]) continue;

            auto it = upper_bound(s.begin(), s.end(), pairs[i][0]);
            if(it == s.end()) s.push_back(pairs[i][1]);
            else if((*it) > pairs[i][1]) (*it) = pairs[i][1];
        }
        return s.size();
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), 
            [](vector<int>& v1, vector<int>& v2){
                return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
            }
        );
        int curr = pairs[0][1],  ret = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] == pairs[i - 1][0]) continue;
            if(curr < pairs[i][0]){
                ret++;
                curr = pairs[i][1];
            }
            else
                curr = min(curr, pairs[i][1]);
        }
        return ret;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(),
            [](vector<int>& v1, vector<int>& v2){
                return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] < v2[1];
            }
        );
        int curr = pairs[0][1], ret = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][1] == pairs[i - 1][1]) continue;
            if(pairs[i][0] > curr){
                curr = pairs[i][1];
                ret++;
            }
        }
        return ret;
    }
};