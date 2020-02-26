#include <vector>
using namespace std;


//O(n^2)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        vector<int> num(ratings.size());
        num[0] = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] <= ratings[i - 1]){
                num[i] = 1;
                int j = i - 1;
                while(j >= 0 && ratings[j] > ratings[j + 1] && num[j] <= num[j + 1]){
                    num[j]++;
                    j--;
                }
            }
            else
                num[i] = num[i - 1] + 1;
        }
        int ret = 0;
        for(int i = 0; i < num.size();i++)
            ret += num[i];
        return ret;
    }
};


//O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        int ret = 1;
        int lastnum = 1;
        int lindex = 0, lvalue = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i - 1] == ratings[i]){
                lastnum = 1;
                lindex = i;
                lvalue = lastnum;
            }
            else if(ratings[i - 1] < ratings[i]){
                lastnum++;
                lindex = i;
                lvalue = lastnum;
            }
            else{
                if(lvalue > i - lindex)
                    ret += i - lindex -1;
                else{
                    ret += i - lindex;
                    lvalue++;
                }
                lastnum = 1;
            }
            ret += lastnum;
        }
        return ret;
    }
};

//O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        int i = 0;
        int ret = 0;
        int lastnum = 1;
        while(i < ratings.size()){
            int j = i + 1;
            while(j < ratings.size() && ratings[j] > ratings[j - 1])
                j++;
            ret += (j - i + 1) * (j - i) / 2;
            if(j == ratings.size() || ratings[j] == ratings[j - 1]){
                i = j;
                continue;
            }
            int maxindex = j - 1;
            int maxnum = j - i;
            while(j < ratings.size() && ratings[j] < ratings[j - 1])
                j++;
            ret += (j - maxindex + 1) * (j - maxindex - 2) / 2;
            ret += max(0, j - maxindex - maxnum);
            i = j - 1;
        }
        return ret;
    }
};


//别人的 O(n) 空间 + O(n)时间
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0)
            return 0;
        
        vector<int> counts(ratings.size(), 1);
        
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) 
                counts[i] = counts[i - 1] + 1;
        }
        
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) 
                counts[i - 1] = max(counts[i] + 1, counts[i - 1]);
        }
        
        int res = 0;
        for (auto n : counts) {
            res += n;
        }
        return res;
    }
};