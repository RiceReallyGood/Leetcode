#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for(int n : nums) count[n]++;
        int index = 0;
        int ret = 0;
        while(index <= 10000){
            while(index <= 10000 && count[index] == 0) index++;
            int start = index;
            while(index <= 10000 && count[index] != 0) index++;
            int end = index - 1;
            ret += deleteSuccessive(count, start, end);
        }
        return ret;
    }

private:
    int deleteSuccessive(vector<int>& count, int start, int end){
        if(start > end) return 0;
        int n = end - start + 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                for(int k = i; k <= j; k++){
                    int temp = count[start + k] * (start + k);
                    if(k >= i + 2) temp += dp[i][k - 2];
                    if(k <= j - 2) temp += dp[k + 2][j];
                    dp[i][j] = max(dp[i][j], temp);
                }
            }
        }
        return dp[0][n - 1];
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> cs(10001, 0);
        for(int n : nums) cs[n]++;
        vector<int> number, count;
        for(int i = 0; i <= 10000; i++){
            if(cs[i] != 0){
                number.push_back(i);
                count.push_back(cs[i]);
            }
        }
        int len = number.size();
        vector<int> d(len, 0), nd(len, 0);
        d[0] = number[0] * count[0];
        nd[0] = 0;
        for(int i = 1; i < len; i++){
            if(number[i] == number[i - 1] + 1){
                d[i] = nd[i - 1] + number[i] * count[i];
                nd[i] = max(nd[i - 1], d[i - 1]);
            }
            else{
                nd[i] = max(d[i - 1], nd[i - 1]);
                d[i] = nd[i] + number[i] * count[i];
            }
        }
        return max(d.back(), nd.back());
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<int> numbers, counts;
        numbers.push_back(nums[0]);
        counts.push_back(1);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == numbers.back()) counts.back()++;
            else{
                numbers.push_back(nums[i]);
                counts.push_back(1);
            }
        }
        
        int d = numbers[0] * counts[0], nd = 0;
        for(int i = 1; i < numbers.size(); i++){
            if(numbers[i] == numbers[i - 1] + 1){
                int temp = nd; 
                nd = max(d, nd);
                d =  nd + numbers[i] * counts[i];
            }
            else{
                nd = max(d, nd);
                d = nd + numbers[i] * counts[i];
            }
        }
        return max(d, nd);
    }
};