#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret = {""};
        for(int i = 0; i < S.length(); i++){
            vector<string> temp;
            if(isalpha(S[i])){
                for(auto str : ret){
                    temp.push_back(str + string(1, tolower(S[i])));
                    temp.push_back(str + string(1, toupper(S[i])));
                }
            }
            else{
                for(auto str : ret)
                    temp.push_back(str + string(1, S[i]));
            }
            swap(ret, temp);
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret = {S};
        for(int i = 0; i < S.size(); i++){
            int currsz = ret.size();
            for(int j = 0; j < currsz; j++){
                if(isalpha(S[i])){
                    string temp = ret[j];
                    temp[i] ^= (1 << 5); // toggle case
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};