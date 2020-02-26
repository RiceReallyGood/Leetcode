#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int findMaximumXOR(vector<int> &nums){
        int mask = 0;
        int maxor = 0;
        for (int i = 31; i >= 0; i--){
            mask |= 1 << i;
            unordered_set<int> prefixs;
            for (int num : nums)
                prefixs.insert(num & mask);
            maxor |= 1 << i;
            auto it = prefixs.begin();
            while (it != prefixs.end()){
                if (prefixs.find((*it) ^ maxor) != prefixs.end())
                    break;
                it++;
            }
            if (it == prefixs.end())
                maxor ^= 1 << i;
        }
        return maxor;
    }
};