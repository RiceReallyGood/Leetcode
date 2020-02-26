#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    int minCut(string s){
        if (s.empty())
            return 0;
        
        vector<int> p = Manacher(s);
        vector<int> mc(s.length() + 1);
        for(int i = 0; i < mc.size() ; i++)
            mc[i] = i - 1;
        for(int len = 1; len <= s.length(); len++){
            for(int sublen = 0; sublen < len; sublen++){
                if(p[sublen + len + 1] >= len - sublen)
                    mc[len] = min(mc[len], mc[sublen] + 1);
            }
        }
        return mc[s.length()];
    }

private:

    vector<int> Manacher(const string &s){
        string new_s = "^";
        for (char c : s){
            new_s.push_back('#');
            new_s.push_back(c);
        }
        new_s += "#$";
        vector<int> p(new_s.length(), 0);
        int center = 2, rightbound = 2;
        for(int i = 0; i < new_s.length() - 1; i++){
            int iMirror = 2 *center - i;
            if( i >= rightbound || i + p[iMirror] == rightbound){
                center = i;
                while(new_s[i + p[i] + 1] == new_s[i - p[i] - 1])
                    ++p[i];
                rightbound = i + p[i];
            }
            else
                p[i] = min(p[iMirror], rightbound - i);
        }
        return p;
    }
};

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};