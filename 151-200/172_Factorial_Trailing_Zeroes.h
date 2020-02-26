#include <algorithm>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int temp = n;
        int twos = 0, fives = 0;
        while(temp){
            temp /= 2;
            twos += temp;
        }
        temp = n;
        while(temp){
            temp /= 5;
            fives += temp;
        }
        return twos < fives ? twos : fives;   
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        while(n){
            n /= 5;
            fives += n;
        }
        return fives;   
    }
};