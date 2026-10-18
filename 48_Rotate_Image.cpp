#include <iostream>
#include "48_Rotate_Image.h"

int main() {
    vector<vector<int>> matrix {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution().rotate(matrix);

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