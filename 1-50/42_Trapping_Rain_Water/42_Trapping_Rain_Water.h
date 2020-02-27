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

class Solution { // Dynamic Programming
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int N = height.size();
        vector<int> leftmax(N), rightmax(N);
        leftmax[0] = height[0];
        rightmax[N - 1] = height[N -1];
        for(int i = 1; i < N; i++)
            leftmax[i] = max(leftmax[i - 1], height[i]);
        for(int i = N - 2; i >= 0; i--)
            rightmax[i] = max(rightmax[i + 1], height[i]);
        int ret = 0;
        for(int i = 0; i < N; i++)
            ret += min(leftmax[i], rightmax[i]) - height[i];
        return ret;
    }
};

class Solution { // Two Pointer
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ret = 0;
        int leftmax = 0, rightmax = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] > leftmax) leftmax = height[left];
                else ret += leftmax - height[left];
                left++;
            }
            else{
                if(height[right] > rightmax) rightmax = height[right];
                else ret += rightmax - height[right];
                right--;
            }
        }
        return ret;
    }
};