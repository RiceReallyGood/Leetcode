#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;


//TLE
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int slen = s.length();
        unordered_set<string> partset;
        for(int start = 0; start <= slen - 10;start++){
            string seq = s.substr(start,10);
            if(partset.find(seq) != partset.end())
                continue;
            if(KMP(s.substr(start + 1, slen - start - 1), seq))
                partset.insert(seq);
        }
        return vector<string>(partset.begin(), partset.end());
    }

    bool KMP(const string &s, const string &p){        
        vector<int> next(p.length());
        next[0] = -1;
        int i = 1, j = 0;
        while(i < s.length()){
            if(p[i] == p[j])
                next[i] = next[j];
            else{
                next[i] = j;
                while(j != -1 && p[i] != p[j])
                    j = next[j];
            }
            i++;
            j++;
        }

        i = 0;
        j = 0;
        while(i < s.length()){
            if(j == p.length())
                break;
            if(j == -1 || s[i] == p[j]){
                i++;
                j++;
            }
            else
                j = next[j];
        }
        return j == p.length();
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int slen = s.length();
        unordered_map<string,int> freqmap;
        for(int start = 0; start <= slen - 10;start++)
            freqmap[s.substr(start, 10)]++;    
        for(auto freq : freqmap)
            if(freq.second > 1)
                ret.push_back(freq.first);
        return ret;
    }
};

class Solution {
private:
    int char2bit(char s){
        switch (s){
            case 'A' : return 0;
            case 'C' : return 1;
            case 'G' : return 2;
            case 'T' : return 3;
        }
        return -1;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if(s.length() <= 10)
            return ret;
        unordered_set<int> appear;
        unordered_set<int> appeartwice;
        int str = 0;
        int mask = (1 << 20) - 1;
        for(int i = 0; i < 10; i++)
            str = (str << 2) | char2bit(s[i]);
        appear.insert(str);
        
        for(int i = 10; i < s.length(); i++){
            str = ((str << 2) & mask) | char2bit(s[i]);
            if(appeartwice.find(str) != appeartwice.end()) continue;
            if(appear.find(str) != appear.end()){
                appeartwice.insert(str);
                ret.push_back(s.substr(i - 9, 10));
            }
            else
                appear.insert(str);
        }
        return ret;
    }
};

class Solution { //标准库里的bitset比unordered_set 快很多 (unordered_set 40ms 而 bitset 8ms 而且省内存)
private:
    int char2bit(char s){
        switch (s){
            case 'A' : return 0;
            case 'C' : return 1;
            case 'G' : return 2;
            case 'T' : return 3;
        }
        return -1;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sizes = s.length();
        if(sizes<=10) return vector<string>();
        vector<string> res;

        bitset<1<<20> S1;  
        bitset<1<<20> S2;  
        int str1 = 0;
        for(int i=0; i<10; i++)
            str1 = (str1<<2) | char2bit(s[i]);
        
        S1.set(str1);

        int mask = (1<<20) - 1;
        for(int i=10; i<sizes; i++){
            str1 = ((str1<<2) & mask) | char2bit(s[i]);
            if(S2[str1]) continue;
            if(S1[str1]){
                res.push_back(s.substr(i-10+1, 10));
                S2.set(str1);
            }
            else S1.set(str1);
        }
        return res;

    }
};