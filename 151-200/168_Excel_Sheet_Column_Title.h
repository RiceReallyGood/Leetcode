#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        int len = 1;
        long sub = 26;
        while(n > sub){
            n -= sub;
            len++;
            sub *= 26;
        }
        n--;
        for(int i = 0; i < len; i++){
            ret.push_back('A' + n % 26);
            n /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n){
            --n;
            ret.push_back(n % 26);
            n /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};