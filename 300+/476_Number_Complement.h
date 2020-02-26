class Solution {
public:
    int findComplement(int num) {
        int maxnz = 0;
        while(num >> maxnz)
            maxnz++;
        return (unsigned(1 << maxnz) - 1) ^ num;
    }
};