#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        RemoveSpaces(s);
        reverse(s.begin(), s.end());
        if(s.back() == ' ')
            s.pop_back();
        int b = 0, e = 0;
        int sz = s.size();
        while(e < sz){
            while(e < sz && s[e] != ' ') ++e;
            reverse(s.begin() + b, s.begin() + e);
            b = e + 1;
            ++e;
        }
        return s;
    }

private:
    void RemoveSpaces(string& s){
        int i = 0, j = 0;
        int sz = s.size();
        while(i + 1 < sz && !(s[i] == ' ' && s[i + 1] == ' ')) { ++i; ++j;}
        ++i; ++j;
        while(j < sz){
            while(j < sz && s[j] == ' ') ++j;
            while(j < sz && s[j] != ' ')
                s[i++] = s[j++];
            s[i++] = ' ';
            j++;
        }
        s.resize(i);
        while(s.back() == ' ')
            s.pop_back();
    }
};