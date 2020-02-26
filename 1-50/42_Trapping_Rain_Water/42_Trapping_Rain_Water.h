#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;

        int vol = 0;
        vector<Node> NStack;
        NStack.push_back({height[0], 0});
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] >= NStack[0].val)
            {
                int h = NStack[0].val;
                int next_index = i;
                while (!NStack.empty())
                {
                    vol += (next_index - NStack.back().index) * (h - NStack.back().val);
                    next_index = NStack.back().index;
                    NStack.pop_back();
                }
                NStack.push_back({height[i], i});
            }
            else
            {
                int h = height[i];
                int next_index = i;
                while (NStack.back().val <= h)
                {
                    vol += (next_index - NStack.back().index) * (h - NStack.back().val);
                    next_index = NStack.back().index;
                    NStack.pop_back();
                }
                NStack.push_back({h, next_index});
            }
        }
        return vol;
    }

    struct Node
    {
        int val;
        int index;
    };
};