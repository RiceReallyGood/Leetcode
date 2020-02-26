#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int maxgap = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            maxgap = max(maxgap, nums[i + 1] - nums[i]);
        return maxgap;
    }
};


class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;                                 // 1, 10, 100, 1000 ...
        int radix = 10;                              // base 10 system

        vector<int> aux(nums.size());

        /* LSD Radix Sort */
        while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++)    // Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

class Solution { //Buckets and The Pigeonhole Principle
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());
        int sz = nums.size();
        int bucketsize = max(1, (max_num - min_num) / (sz - 1));
        vector<pair<int,int>> buckets((max_num - min_num) / bucketsize + 1, make_pair(1, 0));
        for(int i = 0; i < sz; i++){
            int b = (nums[i] - min_num) / bucketsize;
            if(buckets[b].first > buckets[b].second)
                buckets[b].first = buckets[b].second = nums[i];
            else if(nums[i] < buckets[b].first)
                buckets[b].first = nums[i];
            else if(nums[i] > buckets[b].second)
                buckets[b].second = nums[i];
        }

        int maxgap = bucketsize;
        int curr = 1, prev = 0;
        while(curr < buckets.size()){
            if(buckets[curr].first > buckets[curr].second){
                curr++;
                continue;
            }
            maxgap = max(maxgap, buckets[curr].first - buckets[prev].second);
            prev = curr;
            curr++;
        }
        
        return maxgap;
    }
};