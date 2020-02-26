#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if(small.empty() || num < small.top())
            small.push(num);
        else
            large.push(num);
        balance();
    }

    void balance(){
        if(large.size() > small.size()){
            small.push(large.top());
            large.pop();
        }
        else if(small.size() - large.size() > 1){
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
            return double(small.top() + large.top()) / 2.;
        else
            return small.top();
    }

private:
    priority_queue<int> small;
    priority_queue<int,std::vector<int>,std::greater<int>> large;
};