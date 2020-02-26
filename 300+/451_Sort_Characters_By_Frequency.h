#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};
        for(auto& c : s)
            freq[c]++;
        
        multimap<int, char,std::greater<int>> freq_char;
        for(int c = 0; c < 128; c++)
            if(freq[c] != 0)
                freq_char.insert({freq[c], char(c)});
        
        string ret;
        for(auto it = freq_char.begin(); it != freq_char.end(); it++){
            for(int i = 0; i < (*it).first; i++)
                ret.push_back((*it).second);
        }
        return ret;
    }
};