#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> group_tasks(m);
        vector<vector<int>> group_beforeItems(m);
        vector<vector<int>> group_beforeGroups(m);
        for(int i = 0; i < n; i++){
            if(group[i] != -1){
                group_tasks[group[i]].push_back(i);
                for(int j = 0; j < beforeItems[i].size(); j++){
                    if(group[beforeItems[i][j]] == -1)
                        group_beforeItems[group[i]].push_back(beforeItems[i][j]);
                    else if(group[beforeItems[i][j]] != group[i])
                        group_beforeGroups[group[i]].push_back(group[beforeItems[i][j]]);
                }
            }
        }
        vector<bool> task_finished(n, false);
        vector<bool> group_finished(m, false);
        vector<int> ret;
        while(true){
            bool carryon = false;
            for(int i = 0; i < n; i++){
                if(!task_finished[i] && group[i] == -1){
                    if(ready(beforeItems[i], task_finished)){
                        ret.push_back(i);
                        task_finished[i] = true;
                        carryon = true;
                    }
                }
            }
            for(int i = 0; i < m; i++){
                if(!group_finished[i] && ready(group_beforeItems[i], task_finished) && ready(group_beforeGroups[i], group_finished)){
                    if(TopSort(group_tasks[i], beforeItems, task_finished, ret)){
                        group_finished[i] = true;
                        carryon = true;
                    }
                    else
                        return vector<int>();
                }
            }
            if(!carryon)
                break;
        }
        if(ret.size() != n) return vector<int>();
        return ret;
    }

private:
    bool TopSort(vector<int>& items, vector<vector<int>>& beforeItems, vector<bool>& task_finished, vector<int>& ret){
        int count = 0;
        bool carryon = true;
        while(carryon){
            carryon = false;    
            for(int i = 0; i < items.size(); i++){
                if(!task_finished[items[i]] && ready(beforeItems[items[i]], task_finished)){
                    ret.push_back(items[i]);
                    task_finished[items[i]] = true;
                    carryon = true;
                    count++;
                }
            }
        }
        return count == items.size();
    }

    bool ready(vector<int>& beforeitems, vector<bool>& task_finished){
        for(int item : beforeitems)
            if(!task_finished[item]) return false;
        return true;
    }
};