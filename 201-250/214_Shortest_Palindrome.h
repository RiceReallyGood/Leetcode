#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution { //Manacher's Algorithms
public:
    string shortestPalindrome(string s) {
        if(s.empty())
            return s;
        string new_s = "^";
        for (char c : s){
            new_s.push_back('#');
            new_s.push_back(c);
        }
        new_s += "#$";
        vector<int> p(new_s.length(), 0);
        int center = 2, rightbound = 2;
        for(int i = 2; i < new_s.length() - 1; i++){
            int iMirror = 2 * center - i;
            if(i > rightbound || i + p[iMirror] == rightbound){
                center = i;
                if(i + p[iMirror] == rightbound)
                    p[i] = p[iMirror];
                while(new_s[i + p[i] + 1] == new_s[i - p[i] -1])
                    ++p[i];
                rightbound = i + p[i];
            }
            else
                p[i] = min(p[iMirror], rightbound - i);
        }
        center = 1 + s.size();
        int maxleft = center;
        while(1 + p[maxleft] != maxleft)
            --maxleft;
        string ret;
        for(int i = s.size() - 1; i >= p[maxleft]; i--)
            ret.push_back(s[i]);
        ret += s;
        return ret;
    }
};

class Solution { //KMP1
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string new_s = s + "#" + rev + "$";
        int newlen = new_s.length();
        vector<int> next(newlen, 0);
        next[0] = -1;
        for(int i = 1, j = 0; i < newlen; ++i, ++j){
            if(new_s[i] != new_s[j]){
                next[i] = j;
                while(j != -1 && new_s[i] != new_s[j])
                    j = next[j];
            }
            else
                next[i] = next[j];
        }
        return rev.substr(0, len - next[newlen - 1]) + s;
    }
};

class Solution { //KMP2
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string new_s = s + "#" + rev;
        int newlen = new_s.length();
        vector<int> suffixlen(newlen, 0);
        suffixlen[0] = 0;
        for(int i = 1; i < newlen; ++i){
            int j = suffixlen[i - 1];
            while(j != 0 && new_s[i] != new_s[j])
                j = suffixlen[j - 1];
            if(new_s[i] == new_s[j])
                j++;
            suffixlen[i] = j;
        }
        return rev.substr(0, len - suffixlen[newlen - 1]) + s;
    }
};