class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int gcd = GCD(x, y);
        if(gcd == 0)
            return z == 0;
        return z <= x + y && z % gcd == 0;
    }

private:
    int GCD(int a, int b){ return b == 0 ? a : GCD(b, a % b) ;}
};