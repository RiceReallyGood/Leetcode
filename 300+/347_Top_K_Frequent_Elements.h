#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int & num : nums)
            freq[num]++;
        
        class comp{
        public:
            bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
                return p1.second > p2.second;
            }
        };

        priority_queue<pair<int,int>, vector<pair<int, int>>, comp> hp;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(hp.size() < k)
                hp.push(*it);
            else if(hp.top().second < (*it).second){
                hp.pop();
                hp.push(*it);
            }
        }

        vector<int> ret;
        while(!hp.empty()){
            ret.push_back(hp.top().first);
            hp.pop();
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int & num : nums)
            freq[num]++;

        priority_queue<pair<int,int>, vector<pair<int, int>>, std::greater<pair<int, int>>> hp;
        for(auto it = freq.begin(); it != freq.end(); it++){
            hp.push(make_pair((*it).second, (*it).first));
            if(hp.size() > k)
                hp.pop();
        }

        vector<int> ret;
        while(!hp.empty()){
            ret.push_back(hp.top().second);
            hp.pop();
        }
        return ret;
    }
};