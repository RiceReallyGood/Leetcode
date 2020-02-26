#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ret;
        if (words.empty())
            return ret;

        int words_count = words.size();

        map<string, int> word_times;
        for (string word : words)
        {
            if (word_times.find(word) == word_times.end())
                word_times[word] = 1;
            else
                word_times[word]++;
        }

        words.clear();
        vector<int> word_left;
        for (auto it = word_times.begin(); it != word_times.end(); it++)
        {
            words.push_back(it->first);
            word_left.push_back(it->second);
        }

        vector<vector<int>> next(words.size());
        int s_len = s.size();
        int word_len = words[0].size();
        for (int i = 0; i < next.size(); i++)
        {
            next[i].resize(word_len + 1, 0);
            next[i][0] = -1;

            int j = 1, k = 0;
            while (j < word_len)
            {
                if (words[i][j] == words[i][k])
                    next[i][j] = next[i][k];
                else
                {
                    next[i][j] = k;
                    while (k != -1 && words[i][k] != words[i][j])
                        k = next[i][k];
                }
                j++, k++;
            }
            next[i][word_len] = k;
        }

        vector<int> match(s_len, -1);

        for (int i = 0; i < words.size(); i++)
        {
            int j = 0, k = 0;
            while (j < s_len)
            {
                if (k == word_len)
                {
                    match[j - k] = i;
                    k = next[i][word_len];
                    continue;
                }
                if (k == -1 || s[j] == words[i][k])
                    j++, k++;
                else
                    k = next[i][k];
            }
            if (k == word_len)
                match[j - k] = i;
        }

        for (int shift = 0; shift < word_len; shift++)
        {
            int continue_words = 0;
            int j = shift, k = shift;
            while (k < s_len)
            {
                if (match[k] == -1)
                {
                    continue_words = 0;
                    if (j != k)
                    {
                        while (j < k)
                        {
                            word_left[match[j]]++;
                            j += word_len;
                        }
                    }
                    j += word_len;
                }
                else if (word_left[match[k]] > 0)
                {
                    word_left[match[k]]--;
                    continue_words++;
                }
                else
                {
                    while (match[j] != match[k])
                    {
                        word_left[match[j]]++;
                        continue_words--;
                        j += word_len;
                    }
                    j += word_len;
                }
                k += word_len;
                if (continue_words == words_count)
                    ret.push_back(j);
            }
            while (j < s_len && match[j] != -1)
            {
                word_left[match[j]]++;
                j += word_len;
            }
        }
        return ret;
    }
};