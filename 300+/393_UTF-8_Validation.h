#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int sz = data.size();
        int startindex = 0;
        int len = 0;
        while(startindex < sz){
            if((data[startindex] & 0x80) == 0)
                len = 1;
            else if((data[startindex] & 0xE0) == 0xC0)
                len = 2;
            else if((data[startindex] & 0xF0) == 0xE0)
                len = 3;
            else if((data[startindex] & 0xF8) == 0xF0)
                len = 4;
            else
                return false;
            for(int i = 1; i < len; i++){
                startindex++;
                if(startindex == sz || (data[startindex] & 0xC0) != 0x80)
                    return false;
            }
            startindex++;
        }
        return true;
    }
};