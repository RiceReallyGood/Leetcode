#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> minpath(len1 + 1, vector<int>(len2 + 1, 0));
        for (int j = 0; j <= len2; j++)
            minpath[0][j] = j;
        for (int i = 0; i <= len1; i++)
            minpath[i][0] = i;

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                int ins = minpath[i][j - 1] + 1;
                int del = minpath[i - 1][j] + 1;
                int rep = word1[i - 1] == word2[j - 1] ? minpath[i - 1][j - 1] : minpath[i - 1][j - 1] + 1;
                minpath[i][j] = min(min(ins, del), rep);
            }
        }
        return minpath[len1][len2];
    }
};