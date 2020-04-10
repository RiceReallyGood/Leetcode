#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ret;
        stack<int> startindex;
        stack<int> count;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                startindex.push(ret.length());
                count.push(num);
            }
            else if(s[i] == ']'){
                int s = startindex.top(), e = ret.length();
                startindex.pop();
                int num = count.top();
                count.pop();
                for(int t = 1; t < num; t++){
                    ret += ret.substr(s, e - s);
                }
            }
            else
                ret.push_back(s[i]);
        }
        return ret;
    }
};