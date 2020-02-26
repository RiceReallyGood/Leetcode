#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>>& points){
        if(points.size() < 3)
            return points.size();
        int maxpoints = 2;
        for(int i = 0; i < points.size() - maxpoints; i++){
            unordered_map<string,int> linepoint;
            int samepoints = 0;
            for(int j = i + 1; j < points.size(); j++){
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                if( x == 0 && y == 0){
                    samepoints++;
                    continue;
                }
                string k = Frac(y, x).tostr();
                if(linepoint.find(k) != linepoint.end())
                    linepoint[k]++;
                else
                    linepoint[k] = 2;
            }
            for(auto it = linepoint.begin(); it != linepoint.end(); it++)
                maxpoints = max(maxpoints, (*it).second + samepoints);
            maxpoints = max(maxpoints, samepoints + 1);
        }
        return maxpoints;
    }
private:
    class Frac{
    public:    
        Frac(int num_, int den_){
            if(den_ == 0){
                num = 1;
                den = 0;
                return ;
            }
            int gcd = GCD(num_, den_);
            num = num_ / gcd;
            den = den_ / gcd;
            if(den < 0){
                num = -num;
                den = -den;
            }
        }

        string tostr(){
            ostringstream builder;
            builder << num << '#' << den;
            return builder.str();
        }
    
    private:
        int GCD(int a, int b){
            a = abs(a);
            b = abs(b);
            while(a && b){
                if(a > b)   a %= b;
                else    b %= a;
            }
            return a == 0 ? b : a;
        }
        int num, den;
    };
};

class Solution {
public:
    int GCD(int x, int y) {
        return y == 0 ? x : GCD(y, x % y);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int sz = points.size(), res = 0; 
        for (int i = 0; i < sz - res; ++i) {
            map<pair<int, int>, int> m; 
            int duplicate = 1; 
            
            for (int j = i + 1; j < sz; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue; 
                }
                int dx = points[j][0] - points[i][0]; 
                int dy = points[j][1] - points[i][1];
                int gcd = GCD(dx, dy);
                ++m[{dx / gcd, dy / gcd}];
            }
            res = max(res, duplicate);
            for (auto it : m) {
                res = max(res, it.second + duplicate);
            }
        }
        return res;
    }
};