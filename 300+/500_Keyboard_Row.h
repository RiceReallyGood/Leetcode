#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static int line[26] = {2, 1, 1, 2, 3, 2, 2, 2, 3, 2, 2, 2, 1, 1, 3, 3, 3, 3, 2, 3, 3, 1, 3, 1, 3, 1};
        vector<string> ret;
        for(auto& word : words){
            int l = line[tolower(word[0]) - 'a'];
            int j = 1;
            for(; j < word.size(); j++){
                if(line[tolower(word[j]) - 'a'] != l)
                    break;
            }
            if(j == word.size())
                ret.push_back(word);
        }
        return ret;
    }
};