#include <iostream>
#include "54_Spiral_Matrix.h"

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = Solution().spiralOrder(matrix);

    cout << '[';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}