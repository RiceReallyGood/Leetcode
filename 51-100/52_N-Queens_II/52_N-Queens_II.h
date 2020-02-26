#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int ret = 0;
        vector<int> iStack;

        int col = 0;
        int Determined = 0;
        while (!iStack.empty() || col < n)
        {
            if (col < n)
            {
                if (IsValid(iStack, col))
                {
                    iStack.push_back(col);
                    Determined++;
                    if (Determined == n)
                    {
                        ret++;
                        iStack.pop_back();
                        Determined--;
                        col = n;
                    }
                    else
                        col = 0;
                }
                else
                    col++;
            }
            else
            {
                col = iStack.back();
                iStack.pop_back();
                Determined--;
                col++;
            }
        }
        return ret;
    }

    bool IsValid(vector<int> &locations, int col)
    {
        int row = locations.size();
        for (int i = 0; i < locations.size(); i++)
        {
            if (locations[i] == col)
                return false;
            if (i + locations[i] == row + col)
                return false;
            if (i - locations[i] == row - col)
                return false;
        }
        return true;
    }
};