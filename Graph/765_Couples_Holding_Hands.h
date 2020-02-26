#include <vector>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        vector<int> seat(N);
        vector<int> partner(N);
        for(int i = 0; i < N; i += 2){
            seat[row[i]] = i;
            seat[row[i + 1]] = i + 1;
            partner[i] = i + 1;
            partner[i + 1] = i;
        }
        
        int ret = 0;
        for(int i = 0; i < N; i += 2){
            if(partner[row[i]] == row[i + 1]) continue;
            int partnerseat;
            while((partnerseat = seat[partner[row[i + 1]]]) != i){
                //swap(seat[row[i + 1]], seat[row[partner[partnerseat]]]);
                swap(row[i + 1], row[partner[partnerseat]]);
                ret++;
            }
        }
        return ret;
    }
};