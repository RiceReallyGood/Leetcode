#include <vector>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parentcount(n, 0);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1) parentcount[leftChild[i]]++;
            if(rightChild[i] != -1) parentcount[rightChild[i]]++;
        }

        int root = -1;
        for(int i = 0; i < n; i++){
            if(parentcount[i] == 0){
                if(root == -1)
                    root = i;
                else
                    return false;
            }
            else if(parentcount[i] > 1)
                return false;
        }
        return dfs(root, leftChild, rightChild) == n;
    }

private:
    int dfs(int v , vector<int>& leftChild, vector<int>& rightChild){
        if(v == -1) return 0;
        return 1 + dfs(leftChild[v], leftChild, rightChild) + dfs(rightChild[v], leftChild, rightChild);
    }
};