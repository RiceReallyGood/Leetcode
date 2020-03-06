#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26, 0);
        for(char c : p)
            count[c - 'a']++;
        
        vector<int> ret;
        int n = s.size(), m = p.size();
        if(n < m) return ret;
        for(int i = 0; i < m - 1; i++)
            count[s[i] - 'a']--;
        
        for(int i = 0, j = m - 1; j < n; i++, j++){
            count[s[j] - 'a']--;
            bool isAnagrams = true;
            for(int c = 0; c < 26; c++){
                if(count[c] != 0){
                    isAnagrams = false;
                    break;
                }
            }
            if(isAnagrams) ret.push_back(i);
            count[s[i] - 'a']++;
        }
        return ret;
    }
};