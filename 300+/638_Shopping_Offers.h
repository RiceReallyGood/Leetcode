#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int dim = 1;
        int items = needs.size();
        for(int i = 0; i < items; i++)
            dim *= needs[i] + 1;
        vector<int> dp(dim);
        //initialize
        vector<int> v(items, 0);
        for(int i = 0; i < dim; i++){
            int totalprice = 0;
            int n = 0;
            for(int j = 0; j < items; j++){
                totalprice += price[j] * v[j];
                n = n * (needs[j] + 1) + v[j];
            }
            dp[n] = totalprice;
            for(int j = items - 1; j >= 0; j--){
                if(v[j] == needs[j])
                    v[j] = 0;
                else{
                    v[j]++;
                    break;
                }
            }
        }

        //Dynamic Programming
        for(int i = 0; i < special.size(); i++){
            int maxn = INT_MAX, originprice = 0;
            for(int j = 0; j < items; j++){
                if(special[i][j] != 0){
                    maxn = min(maxn, needs[j] / special[i][j]);
                    originprice += price[j] * special[i][j];
                }
            }
            if(maxn == 0 || originprice <= special[i].back())
                continue;
            int dimtmp = 1;
            for(int j = 0; j < items; j++){
                v[j] = needs[j] - special[i][j];
                dimtmp *= v[j] + 1;
            }
            vector<int> vtmp(items, 0);
            for(int k = 0; k < dimtmp; k++){
                int n = 0, newn = 0;
                for(int j = 0; j < items; j++){
                    n = n * (needs[j] + 1) + vtmp[j];
                    newn = newn * (needs[j] + 1) + vtmp[j] + special[i][j];
                }
                dp[newn] = min(dp[newn], dp[n] + special[i].back());
                for(int j = items - 1; j >= 0; j--){
                    if(vtmp[j] == v[j])
                        vtmp[j] = 0;
                    else{
                        vtmp[j]++;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int dim = 1;
        int items = needs.size();
        vector<int> mask(items, 1);
        for(int i = 0; i < items; i++){
            dim *= needs[i] + 1;
            for(int j = 0; j < i; j++)
                mask[j] *= needs[i] + 1;
        }
        vector<int> dp(dim);
        //initialize
        vector<int> v(items, 0);
        int totalprice = 0;
        for(int i = 0; i < dim; i++){
            dp[i] = totalprice;
            for(int j = items - 1; j >= 0; j--){
                if(v[j] == needs[j]){
                    v[j] = 0;
                    totalprice -= price[j] * needs[j];
                }
                else{
                    v[j]++;
                    totalprice += price[j];
                    break;
                }
            }
        }

        //Dynamic Programming
        for(int i = 0; i < special.size(); i++){
            int maxn = INT_MAX, displacement = 0;
            for(int j = 0; j < items; j++){
                if(special[i][j] != 0)
                    maxn = min(maxn, needs[j] / special[i][j]);
                displacement = displacement * (needs[j] + 1) + special[i][j];
            }
            if(maxn == 0 || dp[displacement] <= special[i].back())
                continue;
            int dimtmp = 1;
            for(int j = 0; j < items; j++){
                v[j] = max(needs[j] - special[i][j], -1);
                dimtmp *= v[j] + 1;
            }
            vector<int> vtmp(items, 0);
            int n = 0;
            for(int k = 0; k < dimtmp; k++){
                int newn = n + displacement; 
                dp[newn] = min(dp[newn], dp[n] + special[i].back());
                for(int j = items - 1; j >= 0; j--){
                    if(vtmp[j] == v[j]){
                        vtmp[j] = 0;
                        n -= mask[j] * v[j];
                    }
                    else{
                        vtmp[j]++;
                        n += mask[j];
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int offers = special.size();
        return recurse(price, special, needs, n, offers);
    }

private:
    int recurse(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int n, int offers){
        int totalprice = 0;
        for(int i = 0; i < n; i++)
            totalprice += price[i] * needs[i];

        for(int i = 0; i < offers; i++){
            int j = 0, originprice = 0;
            for(; j < n; j++){
                if(special[i][j] > needs[j])
                    break;
                originprice += price[j] * special[i][j];
            }
            if(j == n && originprice > special[i][n]){
                vector<int> temp(needs);
                for(int k = 0; k < n; k++)
                    temp[k] -= special[i][k];
                totalprice = min(totalprice, special[i][n] + recurse(price, special, temp, n, offers));
            }
        }
        return totalprice;
    }
};