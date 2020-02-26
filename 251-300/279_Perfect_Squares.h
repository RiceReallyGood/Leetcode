#include <queue>
#include <climits>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(n);
        int count = 0;
        while(!q.empty()){
            int sz = q.size();
            count++;
            for(int i = 0; i < sz; i++){
                int num = q.front();
                q.pop();
                int sq = int(std::sqrt(num));
                if(sq * sq == num)
                    return count;
                for(int j = sq; j > 0; j--){
                    int next = num - j * j;
                    if(visited[next])
                        continue;
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return n;
    }
};

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};
        static vector<int> squares{0};
        int sz = dp.size();
        while(squares.back() <= n){
            int num = squares.size();
            squares.push_back(num * num);
        }
        if(sz > n)
            return dp[n];
        dp.resize(n + 1, INT_MAX);

        for(int j = sz; j <= n; j++){
            for(int i = 1; squares[i] <= j; i++)
                if(dp[j] > dp[j - squares[i]] + 1)
                    dp[j] = dp[j - squares[i]] + 1;
        }
        return dp[n];
    }
};

class Solution {
public:
   int numSquares(int n) {
    static vector<int> dp {0};
    int m = dp.size();
    dp.resize(max(m, n+1), INT_MAX);
    for (int i=1, i2; (i2 = i*i)<=n; ++i)
        for (int j=max(m, i2); j<=n; ++j)
            if (dp[j] > dp[j-i2] + 1)
                dp[j] = dp[j-i2] + 1;
    return dp[n];
    }
};