// Definition for a QuadTree node.
#include <vector>
using namespace std;
#define NULL nullptr
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return recurse(grid, 0, 0, grid.size());
    }

private:
    Node* recurse(vector<vector<int>>& grid, int i, int j, int n){
        if(n == 1)
            return new Node(grid[i][j], true);
        
        n /= 2;
        Node *tl = recurse(grid, i, j, n);
        Node *tr = recurse(grid, i, j + n, n);
        Node *bl = recurse(grid, i + n, j, n);
        Node *br = recurse(grid, i + n, j + n, n);
        bool canmerge = true;
        if(!tl->isLeaf) canmerge = false;
        else if(!tr->isLeaf || tr->val != tl->val) canmerge = false;
        else if(!bl->isLeaf || bl->val != tl->val) canmerge = false;
        else if(!br->isLeaf || br->val != tl->val) canmerge = false;

        if(canmerge){
            delete tr;
            delete bl;
            delete br;
            return tl;
        }
        return new Node(1, false, tl, tr, bl, br);
    }
};