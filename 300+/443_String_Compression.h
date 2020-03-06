#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int index = 0;
        for(int i = 1; i <= chars.size(); i++){
            if(i < chars.size() && chars[i] == chars[i - 1]) count++;
            else{
                chars[index++] = chars[i - 1];
                if(count > 1){
                    string ct = to_string(count);
                    for(char c : ct)
                        chars[index++] = c;
                }
                count = 1;
            }
        }
        chars.resize(index);
        return index;
    }
};