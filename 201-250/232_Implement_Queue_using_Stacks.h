#include <stack>
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) { s1.push(x); }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move();
        int ret = s2.top();
        s2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        move();
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); } 

private:
    std::stack<int> s1;
    std::stack<int> s2;
    void move(){
        if(!s2.empty())
            return;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
};