#include <unordered_set>
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for(int i = L; i <= R; i++)
            if(HavePrimeOneBits(i))
                count++;
        return count;
    }

private:
    std::unordered_set<int> smallprimes = {2, 3, 5, 7, 11, 13, 17, 19};
    bool HavePrimeOneBits(int num){
        int ones = 0;
        while(num){
            num = num & (num -1);
            ones++;
        }
        return smallprimes.find(ones) != smallprimes.end();
    }
};