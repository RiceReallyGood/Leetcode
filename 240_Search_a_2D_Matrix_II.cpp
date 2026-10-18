#include <iostream>
#include "240_Search_a_2D_Matrix_II.h"

int main() {
    vector<vector<int>> matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout << (Solution().searchMatrix(matrix, target) ? "true" : "false") << endl;
}