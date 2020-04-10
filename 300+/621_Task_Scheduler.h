#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char c : tasks){
            count[c - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxval = count[25] - 1;
        int idle = n * maxval;
        for(int i = 24; i >= 0; i--)
            idle -= min(count[i], maxval);
        return idle < 0 ? tasks.size() : idle + tasks.size();
    }
};