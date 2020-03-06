#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<Node, vector<Node>, comp> pqcap;
        for(int i = 0; i < Capital.size(); i++)
            pqcap.push(Node(Capital[i], Profits[i]));
        
        priority_queue<int> pf;

        for(int i = 0; i < k; i++){
           while(!pqcap.empty() && pqcap.top().cap <= W){
                Node node = pqcap.top();
                pqcap.pop();
                pf.push(node.pro);
            }
            if(pf.empty()) break;
            W += pf.top();
            pf.pop();
        }
        return W;
    }

private:
    class Node{
    public:
        int cap;
        int pro;
        Node(int capital, int profit) : cap(capital), pro(profit) {}
    };

    class comp{
    public:
        bool operator()(const Node& n1, const Node& n2){
            return n1.cap > n2.cap;
        }
    };
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int N = Capital.size();
        vector<pair<int, int>> cap_pro;
        for(int i = 0; i < N; i++)
            cap_pro.push_back(make_pair(Capital[i], Profits[i]));
        sort(cap_pro.begin(), cap_pro.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first;});
        int index = 0;    
        priority_queue<int> pf;

        for(int i = 0; i < k; i++){
            while(index < N && cap_pro[index].first <= W)
                pf.push(cap_pro[index++].second);

            if(pf.empty()) break;
            W += pf.top();
            pf.pop();
        }
        return W;
    }
};