#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        auto square = [](int n) {return n * n;};
        while(true){
            int next = 0;
            while(n){
                next += square(n % 10);
                n /= 10;
            }
            if(next == 1)
                return true;
            if(visited.find(next) != visited.end())
                return false;
            visited.insert(next);
            n = next;
        }
        return false;
    }
};

class Solution {
public:
    bool isHappy(int n) {  
        for(auto slow = func(n), fast = func(func(n)); slow != 1 && fast != 1; slow=func(slow), fast= func(func(fast))){
            if (slow == fast)
                return false;
        }    
        return true;
    }
private:    
    int func(int n){
        int ret = 0;
        while(n){
            int r = n % 10;
            ret += r * r;
            n /= 10;
        }
        return ret;
    }
};