#include <vector>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if(N > 5000) return 1;
        N = (N + 24) / 25;
        int dim = max(4, N + 1);
        vector<vector<double>> sametime(dim, vector<double>(dim, 0));
        vector<vector<double>> Afirst(dim, vector<double>(dim, 0));
        vector<pair<int, int>> op(4);
        op[0] = {4, 0}, op[1] = {3, 1}, op[2] = {2, 2}, op[3] = {1, 3};
        sametime[0][0] = 1;
        for(int j = 1; j < dim; j++)
            Afirst[0][j] = 1;
        
        for(int i = 1; i < dim; i++){
            for(int t = 0; t < 4; t++){
                int Aleft = max(0, i - op[t].first);
                for(int j = 1; j < dim; j++){
                    int Bleft = max(0, j - op[t].second);
                    Afirst[i][j] += 0.25 * Afirst[Aleft][Bleft];
                    sametime[i][j] += 0.25 * sametime[Aleft][Bleft];
                }
            }
        }
        return Afirst[N][N] + 0.5 * sametime[N][N];
    }
};