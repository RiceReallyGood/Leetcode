#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = -1;
        vector<int> res;
        while (true) {
            for (int k = 0; k < n; k++) {
                res.push_back(matrix[i][++j]);
            }
            if (--m == 0) break;

            for (int k = 0; k < m; k++) {
                res.push_back(matrix[++i][j]);
            }
            if (--n == 0) break;

            for (int k = 0; k < n; k++) {
                res.push_back(matrix[i][--j]);
            }
            if (--m == 0) break;

            for (int k = 0; k < m; k++) {
                res.push_back(matrix[--i][j]);
            }
            if (--n == 0) break;
        }

        return res;
    }
};