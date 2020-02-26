#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.empty())
            return people;
        int n = people.size();
        vector<vector<int>> ret(n, vector<int>(2, -1));
        auto comp = [](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0] ? true : v1[0] > v2[0] ? false : v1[1] < v2[1];
        };
        sort(people.begin(), people.end(),comp);
        for(int i = 0; i < people.size(); i++){
            int count = 0, index = 0;
            while(count < people[i][1]){
                if(ret[index][0] == -1 || ret[index][0] == people[i][0])  count++;
                index++;
            }
            while(ret[index][0] != -1)
                index++;
            ret[index] = people[i];
        }
        return ret;
    }
};