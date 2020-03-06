#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int index = -1;
        for(int i = 0; i < d.size(); i++){
            if(issunsequence(s, d[i])){
                if(index == -1 || d[index].length() < d[i].length() 
                  || (d[index].length() == d[i].length() && d[index] > d[i])) index = i;
            }
        }
        return index == -1 ? "" : d[index];
    }

private:
    int issunsequence(const string& s1, const string& s2){
        if(s2.length() > s1.length()) return false;
        int canescape = s1.length() - s2.length();
        int i = 0, j = 0;
        for(;j < s2.length() && canescape >= 0; i++){
            if(s1[i] == s2[j])
                j++;
            else
                canescape--;
        }
        return canescape >= 0;
    }
};