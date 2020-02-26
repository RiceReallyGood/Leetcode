#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        string new_s = "^#";
        for(char& c : s){
            new_s.push_back(c);
            new_s.push_back('#');
        }
        new_s.push_back('$');
        vector<int> p(new_s.length(), 0);
        int center = 1, rightbound = 1, iMirror;
        int ret = 0;
        for(int i = 1; i < new_s.length() - 1; i++){
            iMirror = 2 * center - i;
            if(i > rightbound || p[iMirror] + i == rightbound){
                center = i;
                while(new_s[i + p[i] + 1] == new_s[i - p[i] - 1])
                    ++p[i];
                rightbound = i + p[i];
            }
            else
                p[i] = min(p[iMirror], rightbound - i);
            ret += (p[i] + 1) / 2;
        }
        return ret;
    }
};