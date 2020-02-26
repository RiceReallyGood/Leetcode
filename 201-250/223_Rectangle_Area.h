#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int xoverlap = overlap(A, C, E, G);
        int yoverlap = overlap(B, D, F, H);
        return (C- A) * (D -B) - xoverlap * yoverlap + (G - E) * (H - F) ;
    }

private:
    int overlap(int A, int B, int C, int D){
        //return max(0 ,min(B, D) - max(A, C));
        if(A < C)
            return B < C ? 0 : min(B, D) - C;
        else
            return D < A ? 0 : min(B, D) - A;
    }
};