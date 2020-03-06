#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2) return true;
        if(islower(word[0]) && isupper(word[1])) return false;
        int secondcase = isupper(word[1]);
        for(int i = 2; i < word.size(); i++)
            if(isupper(word[i]) != secondcase) return false;
        return true;
    }
};