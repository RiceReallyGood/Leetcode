#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int visited = 0;
        if(isValid(preorder, visited) && visited > preorder.size())
            return true;
        return false;
    }

private:
    bool isValid(string& preorder, int& visited){
        if(visited > preorder.size())
            return false;
        if(preorder[visited] == '#'){
            visited += 2;
            return true;
        }
        while(visited < preorder.size() && preorder[visited] != ',')
            visited++;
        visited++;
        return isValid(preorder, visited) && isValid(preorder, visited);
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder.push_back(',');
        int capacity = 1;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] != ',') continue;
            if(--capacity < 0) return false;
            if(preorder[i - 1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
};