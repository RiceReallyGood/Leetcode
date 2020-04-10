#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ret(n, 0);
        stack<int> index;
        for(int i = n - 1; i >= 0; i--){
            while(!index.empty() && T[i] >= T[index.top()])
                index.pop();
            if(!index.empty())
                ret[i] = index.top() - i;
            index.push(i);
        }
        return ret;
    }
};