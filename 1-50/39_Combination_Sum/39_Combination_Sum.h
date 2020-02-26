#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        if (candidates.empty())
            return ret;

        sort(candidates.begin(), candidates.end());
        unordered_map<int, int> num_index;
        for (int i = 0; i < candidates.size(); i++)
            num_index[candidates[i]] = i;

        vector<int> iStack;
        int index = 0;
        int rest = target;
        while (true)
        {
            if (index == candidates.size())
            {
                if (iStack.empty())
                    break;
                else
                {
                    index = num_index[iStack.back()] + 1;
                    rest += iStack.back();
                    iStack.pop_back();
                }
            }
            else
            {
                int times = rest / candidates[index];
                for (int i = 0; i < times; i++)
                    iStack.push_back(candidates[index]);
                rest -= candidates[index] * times;

                if (rest == 0)
                    ret.push_back(iStack);
                index = candidates.size();
            }
        }
        return ret;
    }
};

class Solution{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
        if(candidates.empty())
            return ret;
        int minnum = candidates[0];
        for(int i = 0 ; i < candidates.size(); i++)
            if(candidates[i] < minnum)
                minnum = candidates[i];
        vector<int> combination(target / minnum + 1);
        recurse(candidates, 0, combination, 0, target);
        return ret;
    }

private:
    void recurse(vector<int>& candidates,int can_index, vector<int>& combination, int com_index ,int target){
        if(target == 0){
            ret.push_back(vector<int>(combination.begin(), combination.begin() + com_index));
            return ;
        }
        if(can_index == candidates.size())
            return;
        
        int maxtimes = target / candidates[can_index];
        for(int i = 0; i <= maxtimes; i++){
            recurse(candidates, can_index + 1, combination, com_index + i, target);
            combination[com_index + i] = candidates[can_index];
            target -= candidates[can_index];
        }
    }
    vector<vector<int>> ret;
};