#include <iostream>
#include "73_Set_Matrix_Zeros.h"

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes(matrix);
    cout << '[';
    for (int i = 0; i < matrix.size(); i++) {
        cout << '[';
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j != matrix[i].size() - 1) {
                cout << ',';
            }
        }
        cout << ']';
        if (i != matrix.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}