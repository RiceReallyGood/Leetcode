#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> ops(26, 0);
        int minop = 0;
        int ret = 0;
        for(int i = 0, j = 0; j < s.length(); j++){
            for(int c = 0; c < 26; c++)
                ops[c]++;
            ops[s[j] - 'A']--;
            minop = min(minop + 1, ops[s[j] - 'A']);
            while(minop > k){
                for(int c = 0; c < 26; c++)
                    ops[c]--;
                ops[s[i] - 'A']++;
                for(int c = 0; c < 26; c++)
                    minop = min(minop, ops[c]);
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxduplicate = 0;
        int ret = 0;
        for(int i = 0, j = 0; j < s.length(); j++){
            count[s[j] - 'A']++;
            maxduplicate = max(maxduplicate, count[s[j] - 'A']);
            while(j - i + 1 - maxduplicate > k){
                count[s[i] - 'A']--;
                maxduplicate--;
                for(int c = 0; c < 26; c++)
                    maxduplicate = max(maxduplicate, count[c]);
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        MaxIndexHeap mih(vector<int>(26, 0));
        int ret = 0;
        for(int i = 0, j = 0; j < s.length(); j++){
            mih.increase(s[j] - 'A', 1);
            while(j - i + 1 - mih.top() > k){
                mih.increase(s[i] - 'A', -1);
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }

private:
    class MaxIndexHeap{
    public:
        MaxIndexHeap(const std::vector<int>& data_) : data(data_), indices(data_.size()),
                                            reverse(data_.size()), count(data_.size()),
                                            cap(data_.size())
        {
            for(int i = 0; i < count; i++){
                indices[i] = i;
                reverse[i] = i;
            }
            heapify();
        }

        ~MaxIndexHeap() {}

        int top(){ return data[indices[0]]; }

        void increase(int index, int diff){
            data[index] += diff;
            shiftDown(reverse[index]);
            shiftUp(reverse[index]);
        }
    
    private:
        std::vector<int> indices;
        std::vector<int> reverse;
        std::vector<int> data;

        int count;
        int cap;

        void shiftDown(int k){
            int j = 0;
            while((j = 2 * k + 1) < count){
                if(j < count - 1 && data[indices[j]] < data[indices[j + 1]])
                    j = j + 1;
                
                if(data[indices[k]] >= data[indices[j]]) break;

                std::swap(indices[j], indices[k]);
                reverse[indices[j]] = j;
                reverse[indices[k]] = k;
                k = j;
            }
        }

        void shiftUp(int k){
            int j = 0;
            while(k > 0){
                j = (k - 1) / 2;
                if(data[indices[j]] >= data[indices[k]]) break;
                std::swap(indices[j], indices[k]);
                reverse[indices[j]] = j;
                reverse[indices[k]] = k;
                k = j;
            }
        }

        void heapify(){
            for(int k = (count - 1 - 1) / 2; k >= 0; k--)
                shiftDown(k);
        }
    };
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxduplicate = 0;
        int i = 0, j = 0;
        for(; j < s.length(); j++){
            if(++count[s[j] - 'A'] > maxduplicate)
                maxduplicate++;
            else if(j - i + 1 > k + maxduplicate)
                count[s[i++] - 'A']--;
        }
        return j - i;
    }
};