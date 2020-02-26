#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 2)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ret = 0;
        for(int i = 2; i < n; i++){
            for(int j = 1; j < i; j++){
                long prev = 2L * long(A[j]) - long(A[i]);
                for(int k = 0; k < j; k++)
                    if(A[k] == prev)
                        dp[j][i] += dp[k][j] + 1;
                ret += dp[j][i];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 2)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        multimap<int,int> num_index;
        num_index.insert(make_pair(A[0],0));
        int ret = 0;
        for(int i = 2; i < n; i++){
            for(int j = 1; j < i; j++){
                long prev = 2L * long(A[j]) - long(A[i]);
                auto it = num_index.lower_bound(prev);
                while(it != num_index.end() && (*it).first == prev){
                    if((*it).second < j)
                        dp[j][i] += dp[(*it).second][j] + 1;
                    it++;
                }
                ret += dp[j][i];
            }
            num_index.insert(make_pair(A[i - 1], i - 1));
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 2)
            return 0;
        vector<unordered_map<long, int>> dp(n);
        int ret = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                long delta = long(A[i]) - long(A[j]);
                if(dp[j].find(delta) != dp[j].end()){
                    dp[i][delta] += dp[j][delta] + 1;
                    ret += dp[j][delta];
                }
                else
                    dp[i][delta] += 1;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        unordered_map<long, unordered_map<long, int>> m;
        unordered_multiset<int> s(begin(A), end(A));
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            if (m.count(A[i])) { // exists valid slices ending with A[i]
                for (auto &it : m[A[i]]) {
                    long diff = it.first;
                    int cnt = it.second;
                    res += cnt; // update result with valid #
                    // try to find the next number in the sequence
                    // if it exists, update its count of diff since we can 
                    // append "next" to all valid sequences ending with A[i]
                    long next = A[i] + diff;
                    if (s.count(next))
                        m[next][diff] += cnt;
                }
            }
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - A[j];
                if (diff < INT_MIN || diff > INT_MAX) 
                    continue;
                long next = A[i] + diff;
                // A[j], A[i], next forms a new valid sequence
                if (s.count(next))
                    m[next][diff]++;
            }
            // remove A[i] to avoid duplicate counting
            s.erase(s.find(A[i]));
        }
        return res;
    }
};