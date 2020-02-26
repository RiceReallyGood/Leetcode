#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> uns = {1};
        static int p2 = 0, p3 = 0, p5 = 0;
        static int next2 = 2, next3 = 3, next5 = 5;
        
        while(uns.size() < n){
            uns.push_back(std::min({next2, next3, next5}));
            if(next2 == uns.back()) next2 = uns[++p2] * 2;
            if(next3 == uns.back()) next3 = uns[++p3] * 3;
            if(next5 == uns.back()) next5 = uns[++p5] * 5;
        }
        return uns[n - 1];
    }
};