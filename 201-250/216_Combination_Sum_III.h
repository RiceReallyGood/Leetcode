#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        int rest = n - k * (k + 1) / 2;
        if(k > 9 || k < 1 || rest < 0 || (18 - k + 1) * (18 - k + 2) / 2 < n)
            return ret;
        vector<int> iStack(k);
        for(int i = 0; i < k; i++)
            iStack[i] = i + 1;
        iStack.back() += rest;
        rest = 0;
        while(true){
            if(iStack.back() < 10)
                ret.push_back(iStack);
            while(!iStack.empty() && (k - iStack.size()) * iStack.back() + (k - iStack.size() + 1) * (k - iStack.size() + 2) / 2 > rest){
                rest += iStack.back();
                iStack.pop_back();
            }
            if(iStack.empty())
                break;
            iStack.back()++;
            rest--;
            while(iStack.size() < k - 1){
                rest -= iStack.back() + 1;
                iStack.push_back(iStack.back() + 1);
            }
            iStack.push_back(rest);
            rest = 0;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int rest = n - k * (k + 1) / 2;
        if(k > 9 || k < 1 || rest < 0 || (18 - k + 1) * (18 - k + 2) / 2 < n)
            return ret;
        vector<int> combination(k);
        recurse(combination, 0, n, 1);
        return ret;
    }

private:
    void recurse(vector<int>& combination, int index, int target, int smallest){
        if(target == 0 && index == combination.size()){
            ret.push_back(vector<int>(combination.begin(), combination.begin() + index));
            return;
        }
        if(index == combination.size() || smallest == 10)
            return;
        
        combination[index] = smallest;
        if(target >= smallest)
            recurse(combination, index + 1, target - smallest, smallest + 1);
        if(target >= 0)
            recurse(combination, index, target, smallest + 1);
    }
    vector<vector<int>> ret;
};