#include <iostream>
#include "56_Merge_Intervals.h"
using namespace std;

int main()
{
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution().merge(intervals);
}