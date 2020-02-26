#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> indices(n, vector<int>(6));
        vector<vector<int>> sums(n, vector<int>(3));
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
            indices[i][0] = i + 1 - k;
            sums[i][0] = sum;
            indices[i][1] = i + 1 - 2 * k;
            indices[i][2] = i + 1 - k;
            sums[i][1] = sum;
            indices[i][3] = i + 1 - 3 * k;
            indices[i][4] = i + 1 - 2 * k;
            indices[i][5] = i + 1 - k;
            sums[i][2] = sum;
        }

        int maxi = k - 1;
        for(int i = k; i < n; i++){
            sum = sum + nums[i] - nums[i - k];
            if(sum > sums[i - 1][0]){
                sums[i][0] = sum;
                indices[i][0] = i + 1 - k;
            }
            else{
                sums[i][0] = sums[i - 1][0];
                indices[i][0] = indices[i - 1][0];
            }

            if(sum + sums[i - k][0] > sums[i - 1][1]){
                sums[i][1] = sum + sums[i - k][0];
                indices[i][1] = indices[i - k][0];
                indices[i][2] = i + 1 - k;
            }
            else{
                sums[i][1] = sums[i - 1][1];
                indices[i][1] = indices[i - 1][1];
                indices[i][2] = indices[i - 1][2];
            }

            if(sum + sums[i - k][1] > sums[i - 1][2]){
                sums[i][2] = sum + sums[i - k][1];
                indices[i][3] = indices[i - k][1];
                indices[i][4] = indices[i - k][2];
                indices[i][5] = i + 1 - k;
            }
            else{
                sums[i][2] = sums[i - 1][2];
                indices[i][3] = indices[i - 1][3];
                indices[i][4] = indices[i - 1][4];
                indices[i][5] = indices[i - 1][5];
            }

            if(sums[i][2] > sums[maxi][2]) maxi = i;
        }
        return vector<int>(indices[maxi].begin() + 3, indices[maxi].end());
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 3 * k) return {0, k, 2 * k};
        vector<vector<int>> sums(n, vector<int>(3));
        vector<vector<int>> indices(n, vector<int>(3));
        int sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        sums[k - 1][0] = sum;
        indices[k - 1][0] = 0;
        for(int i = k; i < 2 * k; i++){
            sum = sum - nums[i - k] + nums[i];
            if(sum > sums[i - 1][0]){
                indices[i][0] = i + 1 - k;
                sums[i][0] = sum;
            }
            else{
                indices[i][0] = indices[i - 1][0];
                sums[i][0] = sums[i - 1][0];
            }
        }
        sums[2 * k - 1][1] = sums[k - 1][0] + sum;
        indices[2 * k - 1][1] = k;

        for(int i = 2 * k; i < 3 * k; i++){
            sum = sum - nums[i - k] + nums[i];
            if(sum > sums[i - 1][0]){
                indices[i][0] = i + 1 - k;
                sums[i][0] = sum;
            }
            else{
                indices[i][0] = indices[i - 1][0];
                sums[i][0] = sums[i - 1][0];
            }

            if(sum + sums[i - k][0] > sums[i - 1][1]){
                sums[i][1] = sum + sums[i - k][0];
                indices[i][1] = i + 1 - k;
            }
            else{
                sums[i][1] = sums[i - 1][1];
                indices[i][1] = indices[i - 1][1];
            }
        }
        sums[3 * k - 1][2] = sums[2 * k - 1][1] + sum;
        indices[3 * k - 1][2] = 2 * k;
        for(int i = 3 * k; i < n; i++){
            sum = sum - nums[i - k] + nums[i];
            if(sum > sums[i - 1][0]){
                indices[i][0] = i + 1 - k;
                sums[i][0] = sum;
            }
            else{
                indices[i][0] = indices[i - 1][0];
                sums[i][0] = sums[i - 1][0];
            }

            if(sum + sums[i - k][0] > sums[i - 1][1]){
                sums[i][1] = sum + sums[i - k][0];
                indices[i][1] = i + 1 - k;
            }
            else{
                sums[i][1] = sums[i - 1][1];
                indices[i][1] = indices[i - 1][1];
            }

            if(sum + sums[i - k][1] > sums[i - 1][2]){
                sums[i][2] = sum + sums[i - k][1];
                indices[i][2] = i + 1 - k;
            }
            else{
                sums[i][2] = sums[i - 1][2];
                indices[i][2] = indices[i - 1][2];
            }
        }
        vector<int> ret(3);
        ret[2] = indices.back()[2];
        ret[1] = indices[ret[2] - 1][1];
        ret[0] = indices[ret[1] - 1][0];
        return ret;
    }
};