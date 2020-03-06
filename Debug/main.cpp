#include "class.h"
#include <iostream>

int main(){
    Solution s;
    vector<vector<int>> matrix = {{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}};
    vector<int> cap = {0, 1, 1};
    vector<int> pro = {1, 2, 3};
    for(int i = 1; i <= 15; i++)
        std::cout << i << "    " << s.countArrangement(i) << std::endl;
}