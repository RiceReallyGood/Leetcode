#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for(auto num : nums){
            if(visited.find(num) != visited.end())
                return true;
            visited.insert(num);     
        }
        return false;
    }
};