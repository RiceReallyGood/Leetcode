#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> sub1(m + 1), sub2(n + 1);
        vector<int> ret(k), temp(k);
        for(int len1 = max(k - n, 0); len1 <= min(m, k); len1++){
            MaxSubArray(nums1, sub1, len1);
            MaxSubArray(nums2, sub2, k - len1);
            Merge(sub1, len1, sub2, k - len1, temp);
            if(comp(temp, ret, k) > 0)
                swap(temp, ret);
        }
        return ret;
    }

private:
    void MaxSubArray(vector<int>& nums, vector<int>& sub, int len){
        for(int i = 0; i < len; i++)
            sub[i] = nums[i];
        for(int i = len; i < nums.size(); i++){
            sub[len] = nums[i];
            int j = 0;
            while(j < len && sub[j] >= sub[j + 1]) ++j;
            while(j < len){
                sub[j] = sub[j + 1];
                ++j;
            }
        }
    }

    void Merge(vector<int>& sub1, int len1, vector<int>& sub2, int len2, vector<int>& ret){
        int i = 0, j = 0;
        int index = 0;
        while(i < len1 || j < len2){
            if(j == len2 || ((i < len1) && sub1[i] > sub2[j]))
                ret[index++] = sub1[i++];
            else if(i == len1 || sub1[i] < sub2[j])
                ret[index++] = sub2[j++];
            else{
                int shift = 0;
                while(i + shift + 1 < len1 && j + shift + 1 < len2 && sub1[i + shift + 1] == sub2[j + shift + 1] && sub1[i + shift + 1] >= sub1[i + shift])
                    ret[index++] = sub1[i + shift++];
                ret[index++] = sub1[i + shift];
                if(i + shift == len1 - 1)
                    j += shift + 1;
                else if(j + shift == len2 - 1)
                    i += shift + 1;
                else{
                    if(sub1[i + shift + 1] > sub2[j + shift + 1])
                        i += shift + 1;
                    else if(sub1[i + shift + 1] < sub2[j + shift + 1])
                        j += shift + 1;
                }
            }
        }
    }

    int comp(vector<int>& nums1, vector<int>& nums2, int len){
        for(int i = 0; i < len; i++){
            if(nums1[i] < nums2[i])
                return -1;
            if(nums1[i] > nums2[i])
                return 1;
        }
        return 0;
    }
};