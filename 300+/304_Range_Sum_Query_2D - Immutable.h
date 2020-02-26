#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix){
        int rows = matrix.size();
        int cols = rows == 0 ? 1 : matrix[0].size();
        psum.resize(rows + 1);
        for(int i = 0; i < psum.size() ; i++)
            psum[i].resize(cols + 1, 0);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                psum[i + 1][j + 1] = psum[i + 1][j] + matrix[i][j];
            for(int j = 0; j < cols; j++)
                psum[i + 1][j + 1] += psum[i][j + 1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return psum[row2 + 1][col2 + 1] - psum[row1][col2 + 1] - psum[row2 + 1][col1] + psum[row1][col1];
    }

private:
    vector<vector<int>> psum;
};