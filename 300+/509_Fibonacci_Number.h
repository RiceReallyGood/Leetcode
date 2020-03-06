#include <vector>
using namespace std;

class Solution {
public:
    int fib(int N) {
        static vector<int> fibonacci = {0, 1};
        int i = fibonacci.size() - 2, j = fibonacci.size() - 1;
        while(fibonacci.size() <= N){
            fibonacci.push_back(fibonacci[i] + fibonacci[j]);
            i++, j++;
        }
        return fibonacci[N];
    }
};