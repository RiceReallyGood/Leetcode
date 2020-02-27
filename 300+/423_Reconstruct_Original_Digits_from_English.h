#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(128, 0);
        for(char c : s)
            count[c]++;
        vector<int> digitcount(10);
        digitcount[0] = count['z'];
        for(char c : "zero")
            count[c] -= digitcount[0];
        digitcount[2] = count['w'];
        for(char c : "two")
            count[c] -= digitcount[2];
        digitcount[4] = count['u'];
        for(char c : "four")
            count[c] -= digitcount[4];
        digitcount[1] = count['o'];
        for(char c : "one")
            count[c] -= digitcount[1];
        digitcount[3] = count['r'];
        for(char c : "three")
            count[c] -= digitcount[3];
        digitcount[5] = count['f'];
        for(char c : "five")
            count[c] -= digitcount[5];
        digitcount[6] = count['x'];
        for(char c : "six")
            count[c] -= digitcount[6];
        digitcount[7] = count['v'];
        for(char c : "seven")
            count[c] -= digitcount[7];
        digitcount[8] = count['t'];
        for(char c : "eight")
            count[c] -= digitcount[8];
        digitcount[9] = count['i'];
        for(char c : "nine")
            count[c] -= digitcount[9];
        string ret;
        for(int i = 0; i < 10; i++)
            ret += string(digitcount[i], i + '0');
        return ret;
    }
};