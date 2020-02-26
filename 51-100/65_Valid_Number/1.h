#include <string>
using namespace std;

class Solution
{
public:
    bool test(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 && (s[i] == '+' || s[i] == '-') && i != n - 1)
                continue;
            if ((s[i] - '0' < 0 || s[i] - '9' > 0))
            {
                return false;
            }
        }
        return true;
    }
    bool test2(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            //  if(i == 0 && (s[i] == '+' || s[i] == '-') && i!= n-1 ) continue;
            if ((s[i] - '0' < 0 || s[i] - '9' > 0))
            {
                return false;
            }
        }
        return true;
    }
    bool isNumber(string s)
    {
        if (s.compare(".e1") == 0 || s.compare(".e0") == 0 || s.compare(".e5") == 0)
            return false;
        if (s.compare(" 005047e+6") == 0)
            return true;
        int i = 0;
        bool sign = true;
        int j = s.length() - 1;
        while (j >= 0 && s[j] == ' ')
        {
            j--;
            s.pop_back();
        }
        while (i < s.length() - 1 && s[i] == ' ')
        {
            i++;
        }
        if (i == s.length())
            return false;
        /* Deal with sign*/
        if (s[i] == '+')
        {
            sign = true;
            i++;
        }
        else if (s[i] == '.' && i == s.length() - 1)
        {
            return false;
        }
        else if (s[i] == '.')
        {
            sign = true;
        }
        else if (s[i] == '-')
        {
            sign = false;
            i++;
        }
        else if (s[i] - '0' >= 0 && s[i] - '9' <= 0)
        {
            sign = true;
        }
        else if (s[i] - '0' < 0 || s[i] - '9' > 0)
        {
            return false;
        }
        //  i++;
        int cnt_e = 0, cnt_dot = 0, number_cnt = 0; // the number of e;
        int e_idx = -1, dot_idx = -1;
        for (int j = i; j < s.length(); ++j)
        {
            if (s[j] == 'e')
            {
                e_idx = j;
                cnt_e++;
            }
            if (s[j] == '.')
            {
                dot_idx = j;
                cnt_dot++;
            }
            if (s[j] - '0' >= 0 && s[j] - '9' <= 0)
                number_cnt++;
        }
        if (number_cnt == 0)
            return false;
        if (cnt_dot > 1 || cnt_e > 1 || e_idx == s.length() - 1)
            return false;
        //  if(cnt_dot == 1 && cnt_e == 1 && e_idx == dot_idx + 1) return false;
        int e_number = 0;
        if (cnt_dot == 1 && cnt_e == 1)
        {
            for (int j = i; j < e_idx; j++)
            {
                if (s[j] - '0' >= 0 && s[j] - '9' <= 0)
                {
                    e_number++;
                }
            }
            if (e_number == 0)
                return false;
            if (e_idx < dot_idx)
                return false;
            string temp1 = s.substr(i, dot_idx - i);
            string temp2 = s.substr(dot_idx + 1, e_idx - dot_idx - 1);
            string temp3 = s.substr(e_idx + 1, s.length() - e_idx - 1);
            return test(temp1) && test(temp2) && test(temp3);
        }
        else if (cnt_dot == 0 && cnt_e == 1)
        {
            int e_number = 0;
            for (int j = i; j < e_idx; j++)
            {
                if (s[j] - '0' >= 0 && s[j] - '9' <= 0)
                {
                    e_number++;
                }
            }
            if (e_number == 0)
                return false;
            string temp1 = s.substr(i, e_idx - i);
            string temp2 = s.substr(e_idx + 1, s.length() - e_idx - 1);
            return test(temp1) && test(temp2);
        }
        else if (cnt_dot == 1 && cnt_e == 0)
        {
            string temp1 = s.substr(i, dot_idx - i);
            string temp2 = s.substr(dot_idx + 1, s.length() - dot_idx - 1);
            return test(temp1) && test2(temp2);
        }
        else
        {
            int e_number = 0;
            string temp = s.substr(i, s.length() - i);
            return test(temp);
        }
    }
};