#ifndef MANACHER_H
#define MANACHER_H

#include <string>
#include <vector>

class Manacher{
public:
    Manacher(const std::string& s_) : s(s_) {
        std::string new_s = "^#";
        for(char c : s){
            new_s.push_back(c);
            new_s.push_back('#');
        }
        new_s.push_back('$');
        p.resize(new_s.length(), 0);
        p[0] = 0;
        int center = 0, iMirror = 0, rightbound = 0;
        for(int i = 1; i < new_s.length() - 1; i++){
            iMirror = 2 * center - i;
            if(i > rightbound || i + p[iMirror] == rightbound){
                center = i;
                if(i <= rightbound) p[i] = p[iMirror];
                while(new_s[i - p[i] - 1] == new_s[i + p[i] + 1])
                    p[i]++;
                rightbound = i + p[i];
            }
            else
                p[i] = std::min(p[iMirror], rightbound - i);
        }
    }

    Manacher(const Manacher& rhs) = delete;

    std::string longestPalindromeSubstring(){
        int maxlen = 0, center = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[i] > maxlen){
                maxlen = p[i];
                center = i;
            }
        }
        return s.substr((center - maxlen) / 2, maxlen);
    }

    int lengthoflongestPalindromeSubstring(){
        int maxlen = 0;
        for(int i = 0; i < p.size(); i++)
            maxlen = std::max(maxlen, p[i]);
        return maxlen;
    }

    int PalindromeSubstringCount(){
        int count = 0;
        for(int i = 0; i < p.size(); i++){
            count += (p[i] + 1) / 2;
        }
        return count;
    }

private:
    std::string s;
    std::vector<int> p;
};

#endif