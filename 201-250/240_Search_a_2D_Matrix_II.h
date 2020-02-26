#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();
        if(cols == 0)
            return false;
        return searchMatrix(matrix, 0, rows - 1, 0, cols - 1, target);
    }

private:
    bool searchMatrix(vector<vector<int>>& matrix, int d, int u, int l, int r, int target){
        if(d > u || l > r)
            return false;
        if(d == u && l == r)
            return matrix[u][l] == target;
        int crow = d + (u - d) / 2;
        int ccol = l + (r - l) / 2;
        if(matrix[crow][ccol] == target)
            return true;
        else if(matrix[crow][ccol] < target){
            return searchMatrix(matrix, crow + 1, u, l, r, target) ||
                    searchMatrix(matrix, d, crow, ccol + 1, r, target);
        }
        else{
            return searchMatrix(matrix, d, crow - 1, l, r, target) ||
                searchMatrix(matrix, crow, u, l, ccol - 1, target);
        }
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();
        if(cols == 0)
            return false;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)
                if(matrix[i][j] == target)
                    return true;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();
        if(cols == 0)
            return false;
        return searchMatrix(matrix, 0, rows - 1, 0, cols - 1, target);
    }

private:
    bool searchMatrix(vector<vector<int>>& matrix, int d, int u, int l, int r, int target){
        if(d > u || l > r)
            return false;
        if(d == u && l == r)
            return matrix[u][l] == target;
        int crow = d + (u - d) / 2;
        int ccol = l + (r - l) / 2;
        if(matrix[crow][ccol] == target)
            return true;
        else if(matrix[crow][ccol] < target){
            return searchMatrix(matrix, crow + 1, u, ccol + 1, r, target)||
                searchMatrix(matrix, d, crow, ccol + 1, r, target) ||
                searchMatrix(matrix, crow + 1, u, l, ccol, target);
        }
        else{
            return searchMatrix(matrix, d, crow - 1, l, ccol - 1, target) ||
                searchMatrix(matrix, crow, u, l, ccol - 1, target) ||
                searchMatrix(matrix, d, crow - 1, ccol, r, target);
        }
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = rows == 0 ? 0 : matrix[0].size();
        for(int i = 0, j = cols - 1; i < rows && j >= 0;){
            if(target == matrix[i][j])
                return true;
            if(target < matrix[i][j])
                --j;
            else
                ++i;
        }
        return false;
    }
};
