#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> str_index;
        int sz = words.size();
        for(int i = 0; i < sz; i++)
            str_index[words[i]] = i;
        
        vector<vector<int>> ret;
        for(int i = 0; i< sz; i++){
            string rev(words[i]);
            int len = words[i].length();
            reverse(rev.begin(), rev.end());
            if(rev != words[i] && str_index.find(rev) != str_index.end())
                ret.push_back({str_index[rev], i});
            vector<int> kmp = KMP(words[i]);
            vector<int> revkmp = KMP(rev);
            //left
            int sublen = 0;
            for(int j = 0; j < len; j++){
                while(sublen != 0 && rev[j] != words[i][sublen])
                    sublen = kmp[sublen - 1];
                if(rev[j] == words[i][sublen])
                    sublen++;
            }
            string left;
            while(sublen != 0){
                while(left.length() < len - sublen)
                    left.push_back(rev[left.length()]);
                if(str_index.find(left) != str_index.end())
                    ret.push_back({str_index[left], i});
                sublen = kmp[sublen - 1];
            }
            //right
            for(int j = 0; j < len; j++){
                while(sublen != 0 && words[i][j] != rev[sublen])
                    sublen = revkmp[sublen - 1];
                if(words[i][j] == rev[sublen])
                    sublen++;
            }
            while(sublen != 0){
                string right = rev.substr(sublen, len - sublen);
                if(str_index.find(right) != str_index.end())
                    ret.push_back({i, str_index[right]});
                sublen = revkmp[sublen - 1];
            }
        }
        return ret;
    }

private:
    vector<int> KMP(const string& s){
        int len = s.length();
        vector<int> ret(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j != 0 && s[i] != s[j])
                j = ret[j - 1];
            if(s[i] == s[j])
                j++;
            ret[i] = j;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> str_index;
        int sz = words.size();
        for(int i = 0; i < sz; i++){
            string rev(words[i]);
            reverse(rev.begin(), rev.end());
            str_index[rev] = i;
        }
        
        vector<vector<int>> ret;
        for(int i = 0; i < sz; i++){
            if(words.empty())
                continue;
            vector<int> p = Manacher(words[i]);
            string left;
            int len = 0;
            int center = 1 + words[i].size();
            for(int j = center; j < p.size() - 2; j++){
                if(j + p[j] == p.size() - 2){
                    while(len < words[i].length() - p[j])
                        left.push_back(words[i][len++]);
                    if(str_index.find(left) != str_index.end())
                        ret.push_back({i, str_index[left]});
                }
            }
            for(int j = center; j > 1; j--){
                if(1 + p[j] == j){
                    string right = words[i].substr(p[j], words[i].size() - p[j]);
                    if(str_index.find(right) != str_index.end())
                        ret.push_back({str_index[right], i});
                }
            }

            if(p[center] + 1 != center && str_index.find(words[i]) != str_index.end())
                ret.push_back({str_index[words[i]], i});
        }
        return ret;
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
        return p;
    }
};