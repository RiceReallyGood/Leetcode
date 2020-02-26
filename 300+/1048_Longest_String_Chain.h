#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        auto comp = [](const string& s1, const string& s2){ return s1.length() < s2.length(); };
        sort(words.begin(), words.end(), comp);
        int maxlen = words.back().length();
        vector<int> endindex(maxlen + 1, 0);
        for(int len = 1, index = 0; len <= maxlen; len++){
            while(index < n && words[index].length() == len)
                index++;
            endindex[len] = index;
        }

        vector<int> dp(n, 1);
        int ret = 0;
        for(int len = 2; len <= maxlen; len++){
            for(int i = endindex[len - 1]; i < endindex[len]; i++){
                for(int j = endindex[len - 2]; j < endindex[len - 1]; j++){
                    if(ispredecessor(words[j], words[i]))
                        dp[i] = max(dp[i], dp[j] + 1);
                }
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }

private:
    bool ispredecessor(const string& s1, const string& s2){
        int difference = 0;
        for(int i = 0, j = 0; i < s1.length() && j < s2.length(); j++){
            if(s1[i] == s2[j])
                i++;
            else if(difference == 1)
                return false;
            else
                difference = 1;
        }
        return true;
    }
};