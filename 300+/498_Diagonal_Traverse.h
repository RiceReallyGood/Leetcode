#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = -1;
        vector<int> ret;
        int i , j, bound;
        for(int sum = 0; sum < m + n - 1; sum++){
            if(dir == 1){
                i = sum >= n ? sum - n + 1 : 0;
                j = sum - i;
                bound = min(sum + 1, m);
                for(; i < bound; i++, j--)
                    ret.push_back(matrix[i][j]);
            }
            else{
                i = sum >= m ? m - 1 : sum;
                j = sum - i;
                bound = min(sum + 1, n);
                for(; j < bound; i--, j++)
                    ret.push_back(matrix[i][j]);
            }
            dir = -dir;
        }
        return ret;
    }
};