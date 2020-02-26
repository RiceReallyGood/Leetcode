#include <vector>
#include <unordered_map>
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
        int word_len = words[0].size();

        int s_len = s.size();

        unordered_map<string, int> word_times;
        for (string word : words)
        {
            if (word_times.find(word) == word_times.end())
                word_times[word] = 1;
            else
                word_times[word]++;
        }

        for (int shift = 0; shift < word_len; shift++)
        {
            int continue_words = 0;
            int j = shift, k = shift;
            while (k + word_len <= s_len)
            {
                string substr_k = s.substr(k, word_len);
                if (word_times.find(substr_k) == word_times.end())
                {
                    continue_words = 0;
                    if (j != k)
                    {
                        while (j < k)
                        {
                            word_times[s.substr(j, word_len)]++;
                            j += word_len;
                        }
                    }
                    j += word_len;
                }
                else if (word_times[substr_k] > 0)
                {
                    word_times[substr_k]--;
                    continue_words++;
                }
                else
                {
                    while (s.substr(j, word_len) != substr_k)
                    {
                        word_times[s.substr(j, word_len)]++;
                        continue_words--;
                        j += word_len;
                    }
                    j += word_len;
                }
                k += word_len;
                if (continue_words == words_count)
                    ret.push_back(j);
            }
            while (j + word_len <= s_len && word_times.find(s.substr(j, word_len)) != word_times.end())
            {
                word_times[s.substr(j, word_len)]++;
                j += word_len;
            }
        }

        return ret;
    }
};