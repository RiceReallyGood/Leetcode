#include <unordered_map>
#include <vector>
using namespace std;

class Solution { //canwin[state] 的意思是状态为state时先选放能否必胜
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int totalsum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(totalsum < desiredTotal)
            return false;
        if(totalsum == desiredTotal)
            return maxChoosableInteger % 2;
        unordered_map<int, bool> canwin;
        return recurse((1 << maxChoosableInteger) - 1, desiredTotal, canwin);
    }

private:
    bool recurse(int state, int desiredTotal,unordered_map<int, bool>& canwin){
        if(canwin.find(state) != canwin.end())
            return canwin[state];
        int maxnumleft = MaxBitIndex(state);
        if(maxnumleft  >= desiredTotal)
            return canwin[state] = true;
        
        for(int i = 1; i <= maxnumleft; i++){
            if((state | (1 << (i - 1))) != state)
                continue;
            if(!recurse(state ^ (1 << (i - 1)), desiredTotal - i, canwin))
                return canwin[state] = true;
        }
        return canwin[state]= false;
    }

    int MaxBitIndex(int n){
        int ret = 0;
        while(n){
            n >>= 1;
            ret++;
        }
        return ret;
    }
};

class Solution { //canwin[state] 的意思是状态为state时先选放能否必胜 -1代表未知， 0 代表不能 1代表能
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int totalsum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(totalsum < desiredTotal)
            return false;
        if(totalsum == desiredTotal)
            return maxChoosableInteger % 2;
        vector<int8_t> canwin(1 << maxChoosableInteger, -1);
        return recurse((1 << maxChoosableInteger) - 1, maxChoosableInteger, desiredTotal, canwin);
    }

private:
    int8_t recurse(int state, const int& range ,int desiredTotal,vector<int8_t>& canwin){
        if(canwin[state] != -1)
            return canwin[state];
        
        for(int i = range; i >= 1; i--){
            if(!(state & (1 << (i - 1))))
                continue;
            if(i >= desiredTotal || recurse(state ^ (1 << (i - 1)), range,desiredTotal - i, canwin) == 0)
                return canwin[state] = 1;
        }
        return canwin[state]= 0;
    }
};