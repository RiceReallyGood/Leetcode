#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> originindex(sz);
        vector<int> newindex(sz);
        vector<int> count(sz);
        vector<int> beforemerge(nums.begin(), nums.end());
        vector<int> aftermerge(sz);
        for(int i = 0; i < sz; i++)
            originindex[i] = i;
        
        merge(beforemerge, aftermerge, originindex,newindex, count);
        return count;
    }

private:
    void merge(vector<int>& beformerge, vector<int>& aftermerge, vector<int>& originindex,vector<int>& newindex, vector<int> & count){
        if(beformerge.empty())
            return;
        int l = 0, r = beformerge.size() - 1;
        merge(beformerge, aftermerge, originindex, newindex, count, l, r);
    }

    void merge(vector<int>& beformerge, vector<int>& aftermerge, vector<int>& originindex,vector<int>& newindex, vector<int> & count, int l, int r){
        if(l == r)
            return;
        int c = l + (r - l) / 2;
        merge(beformerge, aftermerge, originindex, newindex, count, l, c);
        merge(beformerge, aftermerge, originindex, newindex, count, c + 1, r);
        int i = l, j = c + 1;
        int k = l;
        while(i <= c && j <= r){
            if(beformerge[i] <= beformerge[j]){
                aftermerge[k] = beformerge[i];
                newindex[k] = originindex[i];
                count[newindex[k]] += j - c - 1;
                ++k, ++i;
            }
            else{
                aftermerge[k] = beformerge[j];
                newindex[k] = originindex[j];
                ++k, ++j;
            }
        }
        if(i > c){
            while(j <= r){
                aftermerge[k] = beformerge[j];
                newindex[k] = originindex[j];
                ++k, ++j;
            }
        }
        if(j > r){
            while(i <= c){
                aftermerge[k] = beformerge[i];
                newindex[k] = originindex[i];
                count[newindex[k]] += j - c - 1;
                ++k, ++i;
            }
        }

        for(i = l; i <= r; i++){
            swap(originindex[i], newindex[i]);
            swap(aftermerge[i],beformerge[i]);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> count(sz);
        if(sz < 2) 
            return count;
        vector<int> index(sz);
        vector<int> tempindex(sz);
        vector<int> tempele(sz);
        for(int i = 0; i < sz; i++)
            index[i] = i;
        
        merge(nums, tempele, index, tempindex, count, 0, sz - 1);
        return count;
    }

private:
    void merge(vector<int>& beformerge, vector<int>& aftermerge, vector<int>& originindex,vector<int>& newindex, vector<int> & count, int l, int r){
        if(l == r)
            return;
        int c = l + (r - l) / 2;
        merge(beformerge, aftermerge, originindex, newindex, count, l, c);
        merge(beformerge, aftermerge, originindex, newindex, count, c + 1, r);
        int i = l, j = c + 1;
        int k = l;
        while(i <= c || j <= r){
            if(j > r || (i <= c && beformerge[i] <= beformerge[j])){
                aftermerge[k] = beformerge[i];
                newindex[k] = originindex[i];
                count[newindex[k]] += j - c - 1;
                ++k, ++i;
            }
            else{
                aftermerge[k] = beformerge[j];
                newindex[k] = originindex[j];
                ++k, ++j;
            }
        }
        for(i = l; i <= r; i++){
            originindex[i] = newindex[i];
            beformerge[i] = aftermerge[i];
        }
    }
};

//Binary Index Tree Solution
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret, clone = nums;;
        int len = (int) nums.size();
        unordered_map<int, int> rank;
        array.resize(len + 1);
        sort(clone.begin(), clone.end());
        for (int i = 0; i < len; ++ i)
            rank[clone[i]] = i + 1;
     
        for (int i = len - 1; i >= 0; -- i) {
            clone[i] = query(rank[nums[i]] - 1);
            add(rank[nums[i]], 1);
        }
        return clone;
    }
 
private:
    vector<int> array;
    inline int lowbit(int pos) {
        return pos & -pos;
    }
    void add(int pos, int val) {
        long len = array.size();
        while (pos < len) {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};