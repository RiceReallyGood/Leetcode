#include <vector>
#include <string>
#include <map>
#include <climits>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

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