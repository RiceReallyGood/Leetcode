class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned un = static_cast<unsigned>(n);
        while(un){
            if((un & 1) == ((un >> 1) & 1))
                return false;
            un >>= 1;
        }
        return true;
    }
};