#include <iostream>
//#include <vector>
#include "46_Permutations.h"
using namespace std;

int main(void)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> pers = Solution().permute(nums);
    for (int i = 0; i < pers.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
            cout << pers[i][j] << " ";
        cout << endl;
    }
}