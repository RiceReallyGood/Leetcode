#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = 0;
        for(auto& c : S)
            if(c != '-')
                count++;
        int group = (count - 1) % K + 1;
        int index = 0;
        string ret;
        while(index < S.size()){
            if(S[index] != '-'){
                ret.push_back(toupper(S[index]));
                group--;
            }
            if(group == 0){
                ret.push_back('-');
                group = K;
            }
            index++;
        }
        ret.pop_back();
        return ret;
    }
};