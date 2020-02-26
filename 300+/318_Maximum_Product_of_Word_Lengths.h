#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxp = 0;
        bool chars[26] = {false};
        int sz = words.size();
        for(int i = 0; i < sz; i++){
            for(int l = 0; l < words[i].length(); l++)
                chars[words[i][l] - 'a'] = true;
            for(int j = i + 1; j < sz; j++){
                int k = 0;
                for(k = 0; k < words[j].length(); k++)
                    if(chars[words[j][k] - 'a'])
                        break;
                if(k == words[j].length())
                    maxp = max(maxp, int(words[i].length() * words[j].length()));
            }
            for(int l = 0; l < words[i].length(); l++)
                 chars[words[i][l] - 'a'] = false;
        }
        return maxp;
    }
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> val(n,0);
        int ans=0;
        for(int i = 0;i < n; i++){
            for(char c : words[i]){
                val[i] |= 1<<(c - 'a');
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1;j < n; j++){
                int a = words[i].size(),b = words[j].size();
                if((val[i] & val[j]) == 0) ans = max(a * b , ans);
            }
        }
        return ans;
    }
};
