#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Solution { //TLE
public:
    bool canCross(vector<int>& stones) {
        return recurse(stones, 0, 0);
    }

private:
    bool recurse(vector<int>& stones, int index, int laststep){
        if(index == stones.size() - 1)
            return true;
        int smallpos = stones[index] + laststep - 1;
        int midpos = smallpos + 1;
        int largepos = midpos + 1;
        int nextindex = BinarySearch(stones, smallpos, index + 1);
        if(stones[nextindex] == smallpos && recurse(stones, nextindex, laststep - 1))
            return true;
        while(nextindex < stones.size() && stones[nextindex] < midpos)
            nextindex++;
        if(nextindex < stones.size() && stones[nextindex] == midpos && recurse(stones, nextindex, laststep))
            return  true;
        while(nextindex < stones.size() && stones[nextindex] < largepos)
            nextindex++;
        if(nextindex < stones.size() && stones[nextindex] == largepos && recurse(stones, nextindex, laststep + 1))
            return  true;
        return false;
    }

    int BinarySearch(vector<int>& stones, int target, int l){
        int c;
        int r = stones.size() - 1;
        while(l < r){
            c = l + (r - l) / 2;
            if(stones[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
};

class Solution { //TLE
public:
    bool canCross(vector<int>& stones) {
        int maxstep = 1;
        for(int i = 0; i < stones.size() - 1; i++){
            if(stones[i + 1] - stones[i] > maxstep)
                return false;
            maxstep++;
        }
        return recurse(stones, 0, 0);
    }

private:
    bool recurse(vector<int>& stones, int index, int laststep){
        if(index == stones.size() - 1)
            return true;
        int smallpos = stones[index] + laststep - 1;
        int midpos = smallpos + 1;
        int largepos = midpos + 1;
        int nextindex = index + 1;
        while(nextindex < stones.size() && stones[nextindex] < smallpos)
            nextindex++;
        if(nextindex < stones.size() && stones[nextindex] == smallpos && recurse(stones, nextindex, laststep - 1))
            return true;
        while(nextindex < stones.size() && stones[nextindex] < midpos)
            nextindex++;
        if(nextindex < stones.size() && stones[nextindex] == midpos && recurse(stones, nextindex, laststep))
            return  true;
        while(nextindex < stones.size() && stones[nextindex] < largepos)
            nextindex++;
        if(nextindex < stones.size() && stones[nextindex] == largepos && recurse(stones, nextindex, laststep + 1))
            return  true;
        return false;
    }
};

class Solution { //BFS //TLE
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> positions(stones.begin(), stones.end());
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                if(p.second > 1){
                    if(p.first + p.second - 1 == stones.back())
                        return true;
                    if(positions.find(p.first + p.second - 1) != positions.end())
                        q.push(make_pair(p.first + p.second - 1, p.second - 1));
                }
                if(p.second > 0){
                    if(p.first + p.second == stones.back())
                        return true;
                    if(positions.find(p.first + p.second) != positions.end())
                        q.push(make_pair(p.first + p.second, p.second));
                }
                if(p.first + p.second + 1 == stones.back())
                    return true;
                if(positions.find(p.first + p.second + 1) != positions.end())
                    q.push(make_pair(p.first + p.second + 1, p.second + 1));
            }
        }
        return false;
    }
};

class Solution { //DFS //TLE
public:
    bool canCross(vector<int>& stones) {
        for(int i = 3; i < stones.size(); i++) {
            if(stones[i] > stones[i-1] * 2) {
                return false; 
            }
        }
        for(auto stone : stones)
            positions.insert(stone);
        target = stones.back();
        return DFS(0, 0);
    }

private:
    bool DFS(int pos, int laststep){
        if(pos == target)
            return true;
        if(positions.find(pos) == positions.end())
            return false;
        for(int step = laststep + 1; step >= laststep - 1 && step > 0; --step){
            if(DFS(pos + step, step))
                return true;
        }
        return false;
    }
    unordered_set<int> positions;
    int target;
};

class Solution { //DP1
public:
    bool canCross(vector<int>& stones) {
        int sz = stones.size();
        if(sz == 1)
            return true;
        unordered_map<int,int> pos_index;
        for(int i = 0; i< sz; i++)
            pos_index[stones[i]] = i;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        if(stones[1] != 1)
            return false;
        dp[0][1] = true;
        for(int i = 1; i < sz; i++){
            for(int j = i + 1; j < sz; j++){
                int step = stones[j] - stones[i];
                if(step > 1 && pos_index.find(stones[i] - step + 1) != pos_index.end())
                    dp[i][j] = dp[i][j] || dp[pos_index[stones[i] - step + 1]][i];
                if(step > 0 && pos_index.find(stones[i] - step) != pos_index.end())
                    dp[i][j] = dp[i][j] || dp[pos_index[stones[i] - step]][i];
                if(pos_index.find(stones[i] - step - 1) != pos_index.end())
                    dp[i][j] = dp[i][j] || dp[pos_index[stones[i] - step - 1]][i];
            }
        }
        for(int i = 0; i < sz - 1; i++)
            if(dp[i][sz -1])
                return true;
        return false;
    }
};

class Solution { //DP2
public:
    bool canCross(vector<int>& stones) {
        int sz = stones.size();
        if(sz == 1)
            return true;
        for(int i = 3; i < stones.size(); i++) {
            if(stones[i] > stones[i-1] * 2) {
                return false; 
            }
        }
        unordered_map<int,int> pos_index;
        for(int i = 0; i< sz; i++)
            pos_index[stones[i]] = i;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        if(stones[1] != 1)
            return false;
        dp[0][1] = true;
        for(int i = 1; i < sz; i++){
            if(dp[i - 1][sz - 1])
                return true;
            for(int j = i + 1; j < sz; j++){
                int step = stones[j] - stones[i];
                if(pos_index.find(stones[i] - step - 1) != pos_index.end() && dp[pos_index[stones[i] - step - 1]][i])
                    dp[i][j] = true;
                else if(step > 0 && pos_index.find(stones[i] - step) != pos_index.end() && dp[pos_index[stones[i] - step]][i])
                    dp[i][j] = true;
                else if(step > 1 && pos_index.find(stones[i] - step + 1) != pos_index.end() && dp[pos_index[stones[i] - step + 1]][i])
                    dp[i][j] = true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canCross(vector<int>& stones) {
        for(int i = 3; i < stones.size(); i++) {
            if(stones[i] > stones[i-1] * 2) {
                return false; 
            }
        }
        
        unordered_set<int> stonePositions; 
        for(int stone : stones) 
            stonePositions.insert(stone);
        
        int target = stones.back();
        stack<int> positions;
        stack<int> steps;
        positions.push(0);
        steps.push(0);
        
        while(!positions.empty()) {
            int position = positions.top();
            positions.pop();
            int step = steps.top();
            steps.pop();
            
            for(int nextstep = step - 1; nextstep <= step + 1; nextstep++) {
                if(nextstep <= 0) continue;
                int nextPosition = nextstep + position;
                if(nextPosition == target) return true;
                else if(stonePositions.find(nextPosition) != stonePositions.end()){
                    positions.push(nextPosition);
                    steps.push(nextstep);
                }
            }
        }
        return false; 
    }
};

