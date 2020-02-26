#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> partitions;
        if (s.empty())
            return partitions;
        partitions.push_back({s.substr(0, 1)});
        for(int index = 1; index < s.length(); index++){
            int pnum = partitions.size();
            for(int i = 0; i < pnum; i++){
                if(partitions[i].back() == s.substr(index, 1)){
                    vector<string> temp = partitions[i];
                    temp.pop_back();
                    temp.push_back(string(2, s[index]));
                    partitions.push_back(temp);
                }
                if(partitions[i].size() > 1 && partitions[i][partitions[i].size() - 2] == s.substr(index, 1)){
                    vector<string> temp = partitions[i];
                    string new_s = temp[temp.size() - 2];
                    new_s += temp.back();
                    new_s += s.substr(index, 1);
                    temp.pop_back(),temp.pop_back();
                    temp.push_back(new_s);
                    partitions.push_back(temp);
                }
                partitions[i].push_back(s.substr(index, 1));
            }
        }
        return partitions;
    }
};