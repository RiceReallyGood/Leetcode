#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret;
        vector<string> solution;
        string s;
        if (n == 0)
            return ret;
        unordered_set<int> valid_sums, valid_diffs;
        set<int> valid_cols;
        for (int i = 0; i < n; i++)
            valid_cols.insert(i);
        for (int i = 0; i < 2 * n - 1; i++)
            valid_sums.insert(i);
        for (int i = -n + 1; i < n; i++)
            valid_diffs.insert(i);

        vector<int> ColStack(1, -1);
        int Determined = 0;
        set<int>::iterator it = valid_cols.begin();
        while (!ColStack.empty())
        {
            if (it != valid_cols.end())
            {
                int col = *it;
                int sum = Determined + col;
                int diff = Determined - col;
                if (valid_sums.find(sum) != valid_sums.end() && valid_diffs.find(diff) != valid_diffs.end())
                {
                    ColStack.push_back(col);
                    valid_cols.erase(col);
                    valid_sums.erase(sum);
                    valid_diffs.erase(diff);
                    Determined++;
                    it = valid_cols.begin();
                }
                else
                    it++;
            }
            else
            {
                Determined--;
                int col = ColStack.back();
                ColStack.pop_back();
                valid_cols.insert(col);
                valid_sums.insert(Determined + col);
                valid_diffs.insert(Determined - col);
                it = valid_cols.find(col);
                it++;
            }
            if (Determined == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    s = string(n, '.');
                    s[ColStack[i]] = 'Q';
                    solution.push_back(s);
                }
                ret.push_back(solution);
                solution.clear();
            }
        }
        return ret;
    }
};