#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sumCD;
        int n = A.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                sumCD[-C[i] - D[j]]++;
        int count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(sumCD.find(A[i] + B[j]) != sumCD.end())
                    count += sumCD[A[i] + B[j]];
            }
        }
        return count;
    }
};