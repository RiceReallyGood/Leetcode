#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) :weight(w) {
        for(int i = 1; i < weight.size(); i++) weight[i] += weight[i - 1];
        range = weight.back();
    }
    
    int pickIndex() {
        int v = rand() % range;
        int l = 0, r = weight.size() - 1;
        while(l != r){
            int c = l + (r - l) / 2;
            if(weight[c] <= v)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }

private:
    vector<int>& weight;
    int range;
};