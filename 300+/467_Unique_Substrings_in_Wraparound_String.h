#include <string>
using namespace std;


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.length() < 2)
            return p.length();
        char nextletter[26];
        for(int i = 0; i < 25; i++)
            nextletter[i] = 'a' + i + 1;
        nextletter[25] = 'a';
        int len[26] = {0};
        int b = 0, e = 1;
        while(e <= p.length()){
            if(e == p.length() || p[e] != nextletter[p[e - 1] - 'a']){
                while(b < e){
                    len[p[b] - 'a'] = max(len[p[b] - 'a'], e - b);
                    b++;
                }
            }
            e++;
        }

        int ret = 0;
        for(int i = 0; i < 26; i++)
            ret += len[i];
        return ret;
    }
};


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.length() < 2)
            return p.length();
        char nextletter[128];
        for(char c = 'a'; c < 'z'; c++)
            nextletter[c] = c + 1;
        nextletter['z'] = 'a';
        int len[128] = {0};
        len[p[0]] = 1;
        int index = 1;
        int size = 1;
        while(index < p.length()){
            if(p[index] != nextletter[p[index - 1]]) size = 0;
            size++;
            if(size > len[p[index]])
                len[p[index]] = size;
            index++;
        }

        int ret = 0;
        for(int c = 'a'; c <= 'z'; c++)
            ret += len[c];
        return ret;
    }
};