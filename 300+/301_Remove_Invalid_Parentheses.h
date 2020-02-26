#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                left++;
            else if(s[i] == ')'){
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }
        string curr(len - left - right, ' ');
        recurse(s, 0, curr, 0, 0);
        return ret;
    }

private:
    vector<string> ret;
    void recurse(string& s, int s_index, string& curr, int curr_index, int left){
        if(curr_index == curr.length()){
            if(left == 0)
                ret.push_back(curr);
            return;
        }

        if(s_index == s.length())
            return;

        int c = s[s_index];
        if(c != '(' && c != ')'){
            curr[curr_index] = c;
            recurse(s, s_index + 1, curr, curr_index + 1, left);
        }
        else if(c == '('){
            int nextneq = s_index + 1;
            while(nextneq < s.length() && s[nextneq] == c)
                ++nextneq;
            int n = nextneq - s_index;
            recurse(s, nextneq, curr, curr_index, left);
            for(int i = 1; i <= n && curr_index + i <= curr.length(); i++){
                curr[curr_index + i - 1] = c;
                recurse(s, nextneq, curr, curr_index + i, left + i);
            }
        }
        else{ // c == ')'
            int nextneq = s_index + 1;
            while(nextneq < s.length() && s[nextneq] == c)
                ++nextneq;
            int n = nextneq - s_index;
            recurse(s, nextneq, curr, curr_index, left);
            for(int i = 1; i <= n && curr_index + i <= curr.length() && i <= left; i++){
                curr[curr_index + i - 1] = c;
                recurse(s, nextneq, curr, curr_index + i, left - i);
            }
        }
    }
};