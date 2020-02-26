#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxlen = 0;
        for(int i = 0; i < wordDict.size(); i++)
            maxlen = max(maxlen, int(wordDict[i].length()));
        
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