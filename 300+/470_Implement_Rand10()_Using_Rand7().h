#include <unordered_map>
using namespace std;

int rand7();

class Solution {
public:
    int rand10() {
        static unordered_map<int, int> m = {
            {2, 1}, {3, 2}, {5, 3}, {7, 4}, {8, 5},
            {10, 6}, {14, 7}, {15, 8}, {18, 9}, {20, 10}
        };
        int ret = 0;
        while(m.find((ret = multitworand7())) == m.end());
        return m[ret];
    }

private:
    int multitworand7(){
        return rand7() * rand7();
    }
};


class Solution {
public:
    int rand10() {
        int ret = 0;
        int r1 = 0, r2 = 0;
        do{
            r1 = rand7();
            r2 = rand7();
            ret = (r1 - 1) * 7 + r2;
        }while(ret > 40);
        return ret % 10 + 1;
    }
};

class Solution {
public:
    int rand10() {
        int a, b, ret;
        while (true) {
            a = rand7();
            b = rand7();
            ret = b + (a - 1) * 7;
            if (ret <= 40)
                return 1 + (ret - 1) % 10;
            a = ret - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            ret = b + (a - 1) * 7;
            if (ret <= 60)
                return 1 + (ret - 1) % 10;
            a = ret - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            ret = b + (a - 1) * 7;
            if (ret <= 20)
                return 1 + (ret - 1) % 10;
        }
    }
};