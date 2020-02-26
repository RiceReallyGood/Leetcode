#include <unordered_map>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        
        if(rep.find(n) != rep.end())
            return rep[n];
        
        if((n & 1) == 0)
            return rep[n] = 1 + integerReplacement(n >> 1);
        
        return rep[n] = min(2 + integerReplacement((n >> 1) + 1), 1 + integerReplacement(n - 1));
    }

private:
    unordered_map<int,int> rep;
};

class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        while(n != 1){
            if((n & 1) == 0){
                n >>= 1;
                ++count;
            }
            else{
                if(n == 3 || (n & 0b11) == 1){
                    n >>= 1;
                    count += 2;
                }
                else{
                    n = (n >> 1) + 1;
                    count += 2;
                }
            }
        }
        return count;
    }
};