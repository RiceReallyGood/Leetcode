#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ret;
        if(num < 0){
            ret.push_back('-');
            num = -num;
        }

        while(num){
            ret.push_back(num % 7 + '0');
            num /= 7;
        }
        int i = ret[0] == '-' ? 1 : 0, j = ret.size() - 1;
        while(i < j)
            swap(ret[i++], ret[j--]);
        return ret;
    }
};