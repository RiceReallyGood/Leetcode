#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        unordered_map<int,int> nummap;
        int maxlen = 0;
        for(int i : nums)
            maxlen = max(maxlen, fillmap(numset, nummap, i));
        return maxlen;
    }

private:
    int fillmap(unordered_set<int>& numset,unordered_map<int,int> &nummap, int num){
        if(numset.find(num) == numset.end())
            return nummap[num] = 1;
        if(nummap.find(num) != nummap.end())
            return nummap[num];
        else
            return nummap[num] = 1 + fillmap(numset, nummap, num - 1);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxlen = 0;

        for(int num : numset){
            if(numset.find(num - 1) == numset.end()){
                int currnum = num + 1;
                int currlen =1;
                while(numset.find(currnum) != numset.end()){
                    currlen++;
                    currnum++;
                }
                maxlen = max(maxlen, currlen);
            }
        }

        return maxlen;
    }
};