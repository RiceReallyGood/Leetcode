#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> exist(1 << 16, false);
        vector<bool> visited(1 << 16, false);
        int s = encode(start), e = encode(end);
        for(string& s : bank)
            exist[encode(s)] = true;
        if(!exist[e]) return -1;
        if(s == e) return 0;
        vector<int> masks = {3, 2, 1};
        int dist = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            dist++;
            int levelcount = q.size();
            for(int i = 0; i <levelcount; i++){
                int curr = q.front();
                q.pop();
                for(int j = 0; j < 8; j++){
                    for(int mask : masks){
                        int next = curr ^ (mask << (2 * j));
                        if(next == e) return dist;
                        if(exist[next] && !visited[next]){
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }

private :
    int encode(string& s){
        static vector<int> toint = { 0, -1,  1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1};
        int ret = 0;
        for(int i = 0; i < 8; i++)
            ret = ret * 4 + toint[s[i] - 'A'];
        return ret;
    }
};