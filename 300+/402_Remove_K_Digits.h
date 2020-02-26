#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length())
            return "0";
        int i = 0;
        string ret;
        while(i < num.length() && k > 0){
            if(!ret.empty() && num[i] < ret.back()){
                ret.pop_back();
                --k;
            }
            else
                ret.push_back(num[i++]);
        }
        ret += num.substr(i, num.length());
        ret.resize(ret.size() - k);
        i = 0;
        while(ret[i] == '0')
            ++i;
        if(i == ret.length())
            return "0";
        return ret.substr(i, ret.length());
    }
};