#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string cur = "1";
        string next;
        for (int i = 2; i <= n; i++)
        {
            int index = 1;
            char count = '1';
            while (index < cur.size())
            {
                if (cur[index] == cur[index - 1])
                    count++;
                else
                {
                    next += count;
                    next += cur[index - 1];
                    count = '1';
                }
                index++;
            }
            next += count;
            next += cur.back();
            cur = next;
            next.clear();
        }
        return cur;
    }
};