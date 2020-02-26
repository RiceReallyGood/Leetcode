#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for(int i = 0; i < sz; i++){
            x = q.front();
            q.pop();
            q.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() { return q.front(); }
    
    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }

private:
    std::queue<int> q;
};