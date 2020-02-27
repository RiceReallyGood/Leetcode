#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty()) return num2;
        if(num2.empty()) return num1;
        int carry = 0;
        string ret;
        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; i--, j--){
            int dig1 = i >= 0 ? num1[i] - '0' : 0;
            int dig2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = dig1 + dig2 + carry;
            ret.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if(carry != 0) ret.push_back('1');
        for(int i = 0, j = ret.length() - 1; i < j; i++, j--)
            swap(ret[i], ret[j]);
        return ret;
    }
};