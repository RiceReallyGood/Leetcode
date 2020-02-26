#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        for(int i = 0; i < cols; i++)
            heights[i] = matrix[0][i] == '0' ? 0 : 1;
        int maxarea = maxSquareArea(heights);
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++)
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            maxarea = max(maxarea, maxSquareArea(heights));
        }
        return maxarea;
    }

private:
    int maxSquareArea(vector<int>& heights){
        vector<int> istack;
        istack.push_back(-1);
        int sz = heights.size();
        int maxarea = 0;
        for(int i = 0; i < sz; i++){
            while(istack.back() != -1 && heights[istack.back()] >= heights[i]){
                int h = heights[istack.back()];
                istack.pop_back();
                int maxlen = min(h, i - istack.back() - 1);
                maxarea = max(maxarea, maxlen * maxlen);
            }
            istack.push_back(i);
        }
        while(istack.back() != -1){
            int h = heights[istack.back()];
            istack.pop_back();
            int maxlen = min(h, sz - istack.back() - 1);
                maxarea = max(maxarea, maxlen * maxlen);
        }
        return maxarea;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> dp(cols);
        for(int i = 0; i < cols; i++)
            dp[i] = matrix[0][i] == '0' ? 0 : 1;
        int maxlen = 0;
        for(int i = 0; i < cols; i++)
            if(matrix[0][i] == '1'){
                maxlen = 1;
                break;
            }
        for(int i = 1; i < rows; i++){
            vector<int> ndp(cols);
            ndp[0] = matrix[i][0] == '0' ? 0 : 1;
            maxlen = max(maxlen, ndp[0]);
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == '0')
                    ndp[j] = 0;
                else{
                    ndp[j] = 1 + min(min(dp[j - 1], dp[j]), ndp[j - 1]);
                    maxlen = max(maxlen, ndp[j]);
                }
            }
            swap(dp, ndp);
        }
        return maxlen * maxlen;
    }
};