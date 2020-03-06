#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if(nums.empty()) return vector<string>();
        int N = nums.size();
        vector<pair<int, int>> num_index;
        for(int i = 0; i < N; i++)
            num_index.push_back(make_pair(nums[i], i));
        sort(num_index.begin(), num_index.end(), 
            [](pair<int, int>& p1, pair<int, int>& p2) {return p1.first > p2.first;});
        vector<string> ret(N);
        ret[num_index[0].second] = "Gold Medal";
        if(N > 1) ret[num_index[1].second] = "Silver Medal";
        if(N > 2) ret[num_index[2].second] = "Bronze Medal";
        for(int i = 3; i < N; i++)
            ret[num_index[i].second] = to_string(i + 1);
        return ret;
    }
};