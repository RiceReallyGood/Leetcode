#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        vector<int> minpath(triangle.size());
        minpath[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            minpath[i] = minpath[i-1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--)
                minpath[j] = min(minpath[j], minpath[j-1]) + triangle[i][j];
            minpath[0] += triangle[i][0];
        }
        int ret = minpath[0];
        for(int i = 0; i < triangle.size(); i++)
            ret = min(ret, minpath[i]);
        return ret;
    }
};