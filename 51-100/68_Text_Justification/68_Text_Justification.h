#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int LeftLength;
        int Curr = 0, Next = 1;
        string s;
        vector<string> ret;
        while (Curr < words.size())
        {
            LeftLength = maxWidth - words[Curr].length() - 1;
            while (Next < words.size() && LeftLength > 0)
            {
                int len = words[Next].length();
                if (LeftLength < len)
                    break;
                LeftLength -= len + 1;
                Next++;
            }
            if (LeftLength == -1 || Next == words.size())
            {
                s = "";
                while (Curr < Next - 1)
                    s += words[Curr++] + " ";
                s += words[Curr++];
                s.resize(maxWidth, ' ');
                ret.push_back(s);
            }
            else
            {
                int Num = Next - Curr;
                if (Num == 1)
                {
                    s = words[Curr++];
                    s.resize(maxWidth, ' ');
                    ret.push_back(s);
                }
                else
                {
                    int Plus = (LeftLength + 1) % (Num - 1);
                    int Spaces = (LeftLength + 1) / (Num - 1) + 1;
                    s = "";
                    while (Curr < Next - 1)
                    {
                        if (Plus > 0)
                        {
                            s += words[Curr++] + string(Spaces + 1, ' ');
                            Plus--;
                        }
                        else
                            s += words[Curr++] + string(Spaces, ' ');
                    }
                    s += words[Curr++];
                    ret.push_back(s);
                }
            }
            Next = Curr + 1;
        }
        return ret;
    }
};