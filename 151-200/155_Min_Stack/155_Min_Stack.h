#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { minelem.push(INT_MAX); }
    
    void push(int x) {
        elems.push(x);
        minelem.push(min(minelem.top(), x));
    }
    
    void pop() {
        elems.pop();
        minelem.pop();
    }
    
    int top() {return elems.top();}
    
    int getMin() { return minelem.top();}

private:
    stack<int> elems;
    stack<int> minelem;
};