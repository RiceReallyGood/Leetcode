class Solution {
public:
    int addDigits(int num) {
        while(num > 9)
            num = num / 10 + num % 10;
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        int ret = num % 9;
        return ret == 0 ? 9 : ret;
    }
};