#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> breaks(s.length() + 1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxlen = 0;
        for(int i = 0; i < wordDict.size(); i++)
            maxlen = max(maxlen, int(wordDict[i].length()));

        for(int len = 1; len <= maxlen && len <= s.length(); len++)
            if(wordSet.find(s.substr(0, len)) != wordSet.end())
                breaks[len].push_back(s.substr(0, len));
        
        for(int i = 1; i < s.length(); i++){
            if(breaks[i].empty())
                continue;
            for(int len = 1; len <= maxlen && i + len <= s.length(); len++){
                string sub = s.substr(i, len);
                if(wordSet.find(sub) != wordSet.end()){
                    for(string br : breaks[i])
                        breaks[i + len].push_back(br + " " + sub);
                }
            }
        }
        return breaks[s.length()];
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> breaks;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxlen = 0;
        for(int i = 0; i < wordDict.size(); i++)
            maxlen = max(maxlen, int(wordDict[i].length()));
        
        if(!checkwordBreak(s, wordSet, maxlen))
            return breaks;
        
        vector<vector<int>> wordlens(s.length());      
        for(int start = 0; start < s.length(); start++){
            for(int len = 1; len <= maxlen && start + len <= s.length(); len++){
                if(wordSet.find(s.substr(start, len)) != wordSet.end())
                    wordlens[start].push_back(len);  
            }
        }

        vector<int> path;
        GenBreaks(s, wordlens, 0, path, breaks);
        return breaks;
    }

private:
    void GenBreaks(string &s, vector<vector<int>> &wordlens, int start, vector<int>& path,vector<string> &breaks){
        if(start == s.length()){
            string br;
            for(int i = 0; i < path.size() - 1; i++)
                br += s.substr(path[i], path[i + 1] - path[i]) + " ";
            br += s.substr(path.back(), start - path.back());
            breaks.push_back(br);
            return ;
        }
        path.push_back(start);
        for(int len : wordlens[start])
            GenBreaks(s, wordlens, start + len, path, breaks);

        path.pop_back();
    }

    bool checkwordBreak(string s, unordered_set<string>& wordSet, int maxlen) {
        vector<bool> CanBreak(s.length() + 1, false);
        CanBreak[0] = true;
        for(int i = 0; i <= s.length(); i++){
            if(CanBreak[i]){
                for(int len = 1; len <= maxlen && i + len <= s.length(); len++){
                    if(CanBreak[i + len])
                        continue;
                    if(wordSet.find(s.substr(i, len)) != wordSet.end())
                        CanBreak[i + len] = true;
                }
            }
        }
        return CanBreak[s.length()];
    }
};