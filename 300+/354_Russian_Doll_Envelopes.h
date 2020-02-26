#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int,int>> envs(n);
        for(int i = 0; i < n; i++)
            envs[i] = make_pair(envelopes[i][0],envelopes[i][1]);
        sort(envs.begin(), envs.end());
        vector<int> dp(n , 1);
        int curr_beg = 0;
        int maxenv = n == 0 ? 0 : 1;
        for(int i = 1; i < n; i++){
            if(envs[i].first != envs[i - 1].first)
                curr_beg = i;
            for(int j = 0; j < curr_beg; j++){
                if(envs[j].second < envs[i].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxenv = max(maxenv, dp[i]);
        }
        return maxenv;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0] ? true : v1[0] > v2[0] ? false : v1[1] < v2[1];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> minheight;
        int curr = 0, next = 0;
        while(curr < n){
            next++;
            while(next < n && envelopes[next - 1][0] == envelopes[next][0]) next++;
            int i = 0, j = curr, prevheight = 0;
            while(i < minheight.size() && j < next){
                if(envelopes[j][1] <= prevheight) ++j;
                else if(envelopes[j][1] < minheight[i]){
                    prevheight = minheight[i];
                    minheight[i] = envelopes[j][1];
                    ++i, ++j;
                }
                else{
                    prevheight = minheight[i];
                    ++i;
                }
            }
            while(j < next && envelopes[j][1] <= prevheight) j++;
            if(j < next)
                minheight.push_back(envelopes[j][1]);
            curr = next;
        }
        return minheight.size();
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0] ? true : v1[0] > v2[0] ? false : v1[1] > v2[1];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> minheight;
        for(auto & e : envelopes){
            auto it = lower_bound(minheight.begin(), minheight.end(),e[1]);
            if(it == minheight.end())
                minheight.push_back(e[1]);
            else
                *it = e[1];
        }
        return minheight.size();
    }
};