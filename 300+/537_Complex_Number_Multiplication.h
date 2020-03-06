#include <string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar, ai, br, bi;
        stoc(a, ar, ai);
        stoc(b, br, bi);
        return to_string(ar * br - ai * bi) + "+" + to_string(ar * bi + ai * br) + "i";
    }

private:
    void stoc(string a, int& ar, int& ai){
        int plusindex = 0;
        while(a[plusindex] != '+') plusindex++;
        ar = stoi(a.substr(0, plusindex));
        ai = stoi(a.substr(plusindex + 1, a.size() - plusindex - 2));
    }
};