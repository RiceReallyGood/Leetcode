#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;

        sort(candidates.begin(), candidates.end());

        vector<Node> NStack;
        vector<int> v;
        int index = 0;
        int rest = target;
        while (true)
        {
            if (index == candidates.size())
            {
                if (NStack.empty())
                    break;
                else
                {
                    rest += NStack.back().val;
                    index = NStack.back().index + 1;
                    NStack.pop_back();
                    while (index < candidates.size() && candidates[index] == candidates[index - 1])
                        index++;
                }
            }
            else
            {
                while (index < candidates.size() && rest >= candidates[index])
                {
                    NStack.push_back({candidates[index], index});
                    rest -= candidates[index];
                    index++;
                }
                if (rest == 0)
                {
                    for (Node n : NStack)
                        v.push_back(n.val);
                    ret.push_back(v);
                    v.clear();
                }
                index = candidates.size();
            }
        }
        return ret;
    }

    struct Node
    {
        int val;
        int index;
    };
};

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        if(candidates.empty())
            return ret;
        sort(candidates.begin(), candidates.end());
        vector<int> combination(target / candidates[0] + 1);
        recurse(candidates, 0, combination, 0, target);
        return ret;
    }

private:
    void recurse(vector<int>& candidates, int can_index, vector<int>& combination, int com_index, int target){
        if(target == 0){
            ret.push_back(vector<int>(combination.begin(), combination.begin() + com_index));
            return;
        }

        if(can_index == candidates.size())
            return;
        
        int nextindex = can_index + 1;
        while(nextindex < candidates.size() && candidates[nextindex] == candidates[nextindex - 1])
            nextindex++;
        
        for(int i = 0; i <= nextindex - can_index && target >= 0; i++){
            recurse(candidates, nextindex, combination, com_index + i, target);
            combination[com_index + i] = candidates[can_index];
            target -= candidates[can_index];
        }
    }
    vector<vector<int>> ret;
};