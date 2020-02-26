#include <string>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        string ms = "122";
        int i = 2;
        int count = 1;
        int topush = 2;
        char num = '1';
        while(ms.size() < n){
            if(topush){
                ms.push_back(num);
                topush--;
                if(num == '1')
                    count++;
            }
            else{
                i++;
                num = num == '1' ? '2' : '1';
                topush = ms[i] - '0';
            }
        }
        return count;
    }
};