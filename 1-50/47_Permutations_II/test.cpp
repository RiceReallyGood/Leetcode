#include <iostream>
//#include <vector>
#include "47_Permutations_II.h"
using namespace std;

int main(void)
{
    vector<int> nums = {1, 1};
    vector<vector<int>> pers = Solution().permuteUnique(nums);
    for (int i = 0; i < pers.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
            cout << pers[i][j] << " ";
        cout << endl;
    }
}