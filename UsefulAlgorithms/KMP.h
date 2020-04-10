#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

class KMPstr{
public:
    KMPstr(const std::string& s_): s(s_) {
        preprocess();
    }

    KMPstr(const KMPstr& rhs) = delete;

    std::string str() {return s;}

    bool issubstr(const  std::string& sequence){
        for(int i = 0, j = 0; i < sequence.length(); i++){
            while(j != 0 && sequence[i] != s[j])
                j = prefixlen[j - 1];
            if(sequence[i] == s[j])
                j++;
            if(j == s.length())
                return true;
        }
        return false;
    }

    int matchcount(const  std::string& sequence){
        int count = 0;
        for(int i = 0, j = 0; i < sequence.length(); i++){
            while(j != 0 && sequence[i] != s[j])
                j = prefixlen[j - 1];
            if(sequence[i] == s[j])
                j++;
            
            if(j == s.length()){
                count++;
                j = prefixlen[j - 1];
            }
        }
        return count;
    }

private:
    void preprocess(){
        prefixlen.resize(s.length());
        prefixlen[0] = 0;
        for(int i = 1, j = 0; i < s.length(); i++){
            while(j != 0 && s[i] != s[j])
                j = prefixlen[j - 1];
            if(s[i] == s[j])
                j++;
            prefixlen[i] = j;
        }
    }

    std::string s;
    std::vector<int> prefixlen;
};

#endif