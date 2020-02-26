#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution { //brute force
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++){
            int j = 0;
            while(nums2[j] != nums1[i]) j++;
            for(j++; j < nums2.size(); j++)
                if(nums2[j] > nums1[i]){
                    ret[i] = nums2[j];
                    break;
                }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextgreater;
        stack<int> s;
        for(auto& num : nums2){
            while(!s.empty() && num > s.top()){
                nextgreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ret;
        for(auto& num : nums1)
            if(nextgreater.find(num) != nextgreater.end())
                ret.push_back(nextgreater[num]);
            else
                ret.push_back(-1);
        return ret;
    }
};