#include <vector>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> digits;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }
        int len = digits.size();
        for(int i = 0, j = len - 1; i < j; i++, j--)
            swap(digits[i], digits[j]);

        
        vector<int> freedom(len + 1, 0);
        for(int i = len - 1; i >= 0; i--)
            freedom[i] = freedom[i + 1] * 10 + 1;
        
        vector<int> samefreedom(len);
        samefreedom[len - 1] = 1;
        for(int i = len - 2; i >= 0; i--)
            samefreedom[i] = 1 + digits[i + 1] * freedom[i + 1] + (10 - digits[i + 1] - 1) * freedom[i + 2] + samefreedom[i + 1];
        

        bool prevsame = true;
        vector<int> temp(len, 0);
        temp[0] = 1;
        int resindex = 0;
        int shift = 0;
        while(true){
            while(true){
                if(prevsame && temp[resindex] == digits[resindex]){
                    if(samefreedom[resindex] < k){
                        k -= samefreedom[resindex];
                        temp[resindex]++;
                        shift = 1;
                    }
                    else
                        break;
                }
                else{
                    if(freedom[resindex + shift] < k){
                        k -= freedom[resindex + shift];
                        temp[resindex]++;
                    }
                    else
                        break;
                }
            }
            prevsame = prevsame && temp[resindex] == digits[resindex];
            if(k == 1) break;
            k--;
            resindex++;
        }

        int res = 0;
        for(int i = 0; i <= resindex; i++)
            res = res * 10 + temp[i];
        return res;
    }
};