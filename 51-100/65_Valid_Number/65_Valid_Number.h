#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        vector<unordered_map<char, int>> states = {
            {{'b', 0}, {'s', 1}, {'n', 2}, {'d', 3}}, //S0
            {{'n', 2}, {'d', 3}},                     //S1
            {{'n', 2}, {'d', 4}, {'e', 5}, {'b', 8}}, //S2
            {{'n', 4}},                               //S3
            {{'n', 4}, {'e', 5}, {'b', 8}},           //S4
            {{'s', 6}, {'n', 7}},                     //S5
            {{'n', 7}},                               //S6
            {{'n', 7}, {'b', 8}},                     //S7
            {{'b', 8}}                                //S8
        };
        unordered_set<int> ValidStates = {2, 4, 7, 8};
        int CurrentState = 0;
        int c;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                c = 'n';
            else if (s[i] == '+' || s[i] == '-')
                c = 's';
            else if (s[i] == '.')
                c = 'd';
            else if (s[i] == 'e')
                c = 'e';
            else if (s[i] == ' ')
                c = 'b';
            else
                return false;
            if (states[CurrentState].find(c) == states[CurrentState].end())
                return false;
            CurrentState = states[CurrentState][c];
        }
        if (ValidStates.find(CurrentState) == ValidStates.end())
            return false;
        return true;
    }
};