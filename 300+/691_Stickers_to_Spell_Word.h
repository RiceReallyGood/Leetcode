#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if(target.empty()) return 0;
        vector<int> times(26, 0);
        vector<int> masks(26, 0);
        for(char c : target) times[c - 'a']++;
        int mask = 1;
        for(int i = 0; i < 26; i++){
            masks[i] = times[i] == 0 ? 0 : mask;
            mask *= times[i] + 1;
        }
        int dim = mask;
        vector<int> dp(dim, -1);
        dp[0] = 0;
        set<int> states = {0};
        vector<int> v(26, 0);
        for(int i = 0; i < stickers.size(); i++){
            for(int j = 0; j < 26; j++) v[j] = 0;
            for(int j = 0; j < stickers[i].size(); j++) v[stickers[i][j] - 'a']++;
            for(int state : states){
                if(dp[state] != -1){
                    int tmp = state;
                    int new_state = 0;
                    for(int j = 0; j < 26; j++){
                        if(times[j] == 0) continue;
                        new_state += min(times[j], tmp % (times[j] + 1) + v[j]) * masks[j];
                        tmp /= times[j] + 1;                        
                    }
                    if(dp[new_state] == -1){
                        states.insert(new_state);
                        dp[new_state] = dp[state] + 1;
                    }
                    else if(dp[state] + 1 < dp[new_state])
                        dp[new_state] = dp[state] + 1;
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if(target.empty()) return 0;
        vector<int> targetNaiveCount(26, 0);
        for(char c : target) targetNaiveCount[c - 'a']++;
        vector<int> index(26, 0);
        int t = 0;
        for(int i = 0; i < 26; i++){
            if(targetNaiveCount[i] > 0) index[i] = t++;
            else index[i] = -1;
        }
        vector<int> targetCount(t, 0);
        t = 0;
        for(int c : targetNaiveCount)
            if(c > 0) targetCount[t++] = c;
        vector<vector<int>> stickersCount(stickers.size(), vector<int>(t, 0));
        for(int i = 0; i < stickers.size(); i++){
            for(char c : stickers[i]){
                int j = index[c - 'a'];
                if(j != -1) stickersCount[i][j]++;
            }
        }

        int anchor = stickers.size();
        for(int i = 0; i < anchor; i++){
            for(int j = 0; j < anchor; j++){
                if(j == i) continue;
                bool dominated = true;
                for(int k = 0; k < t; k++){
                    if(stickersCount[i][k] > stickersCount[j][k]){
                        dominated = false;
                        break;
                    }
                }
                if(dominated){
                    swap(stickersCount[i], stickersCount[anchor - 1]);
                    i--;
                    anchor--;
                    break;
                }    
            }
        }
        stickersCount.resize(anchor);
        vector<int> masks(t, 0);
        int dim = 1;
        for(int i = 0; i < t; i++){
            masks[i] = dim;
            dim *= targetCount[i] + 1;
        }
        vector<int> dp(dim, -1);
        dp[0] = 0;
        set<int> states = {0};
        for(int i = 0; i < anchor; i++){
            for(int state : states){
                if(dp[dim - 1] != -1 && dp[state] + 1 >= dp[dim - 1]) continue; 
                int tmp = state;
                int new_state = 0;
                for(int j = 0; j < t; j++){
                    new_state += min(targetCount[j], tmp % (targetCount[j] + 1) + stickersCount[i][j]) * masks[j];
                    tmp /= targetCount[j] + 1;                        
                }
                if(dp[new_state] == -1){
                    if(new_state != dim - 1)
                        states.insert(new_state);
                    dp[new_state] = dp[state] + 1;
                }
                else if(dp[state] + 1 < dp[new_state])
                    dp[new_state] = dp[state] + 1;
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if(target.empty()) return 0;
        vector<int> targetNaiveCount(26, 0);
        for(char c : target) targetNaiveCount[c - 'a']++;
        vector<int> index(26, 0);
        int t = 0;
        for(int i = 0; i < 26; i++){
            if(targetNaiveCount[i] > 0) index[i] = t++;
            else index[i] = -1;
        }
        vector<int> targetCount(t, 0);
        t = 0;
        for(int c : targetNaiveCount)
            if(c > 0) targetCount[t++] = c;
        vector<vector<int>> stickersCount(stickers.size(), vector<int>(t, 0));
        for(int i = 0; i < stickers.size(); i++){
            for(char c : stickers[i]){
                int j = index[c - 'a'];
                if(j != -1) stickersCount[i][j]++;
            }
        }

        int anchor = stickers.size();
        for(int i = 0; i < anchor; i++){
            for(int j = 0; j < anchor; j++){
                if(j == i) continue;
                bool dominated = true;
                for(int k = 0; k < t; k++){
                    if(stickersCount[i][k] > stickersCount[j][k]){
                        dominated = false;
                        break;
                    }
                }
                if(dominated){
                    swap(stickersCount[i], stickersCount[anchor - 1]);
                    i--;
                    anchor--;
                    break;
                }    
            }
        }
        stickersCount.resize(anchor);
        int best = target.length() + 1;
        recurse(stickersCount, 0, targetCount, 0, best);
        return best == target.length() + 1 ? -1 : best;
    }

private:
    void recurse(vector<vector<int>>& stickersCount, int index, vector<int>& targetCount, int count, int &best){
        if(count >= best) return;
        if(index == stickersCount.size()){
            for(int c : targetCount)
                if(c > 0) return;
            best = count;
            return;
        }
        int used = 0;
        for (int i = 0; i < stickersCount[index].size(); i++) {
            if (targetCount[i] > 0 && stickersCount[index][i] > 0) {
                used = max(used, (targetCount[i] - 1) / stickersCount[index][i] + 1);
            }
        }

        for(int i = 0; i < targetCount.size(); i++)
            targetCount[i] -= used * stickersCount[index][i];
        recurse(stickersCount, index + 1, targetCount, count + used, best);
        while(used > 0){
            for(int i = 0; i < targetCount.size(); i++)
                targetCount[i] += stickersCount[index][i];
            used--;
            recurse(stickersCount, index + 1, targetCount, count + used, best);
        }
    }
};