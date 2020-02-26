#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int numMatchingSubseq(string S, vector<string> &words)
    {
        int count = 0;
        if (S.empty())
        {
            for (string &word : words)
            {
                if (word.empty())
                    ++count;
            }
            return count;
        }
        for (string &word : words)
        {
            if (word.empty())
                continue;
            int *next = findNext(word);
            int wlen = word.size(), slen = S.size();
            int i = 0, j = 0;
            while (i < wlen && j < slen)
            {
                if (i == -1 || word[i] == S[j])
                {
                    ++i;
                    ++j;
                }
                else
                    i = next[i];
            }
            if (i == word.size())
                ++count;
            delete[] next;
        }
        return count;
    }

    int *findNext(string &pattern)
    {
        int len = pattern.size();
        if (len == 0)
            return NULL;
        int *next = new int[len];
        next[0] = -1;
        int i = 0, k = -1;
        while (i < len - 1)
        {
            while (k >= 0 && pattern[i] != pattern[k])
                k = next[k];
            ++i;
            ++k;
            if (pattern[i] == pattern[k])
                next[i] = next[k];
            else
                next[i] = k;
        }
        return next;
    }
};