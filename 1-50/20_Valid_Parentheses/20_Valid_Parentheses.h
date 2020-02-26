#include <string>
#include <set>
#include <map>
using namespace std;

class Solution
{
  public:
	bool isValid(string s)
	{
		set<char> opens = {'(', '[', '{'};
		map<char, char> close_open = {{')', '('}, {']', '['}, {'}', '{'}};
		string cStack;
		for (char c : s)
		{
			if (opens.find(c) != opens.end())
				cStack.push_back(c);
			else
			{
				if (cStack.empty() || cStack.back() != close_open[c])
					return false;
				else
					cStack.pop_back();
			}
		}
		return cStack.empty();
	}
};