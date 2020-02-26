class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.length();
        int end = sz-1;
        int start = 0; 
        while(start < end){
            while(!isalnum(s[start]) && start < end)
               start++;
            while(!isalnum(s[end]) && start < end)
               end--;
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};