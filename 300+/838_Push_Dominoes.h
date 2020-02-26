#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.empty()) return dominoes;
        int n = dominoes.length();
        vector<int> leftposition(n), rightposition(n);
        leftposition[0] = dominoes[0] == 'R' ? 0 : -1;
        for(int i = 1; i < n; i++){
            if(dominoes[i] == 'R') leftposition[i] = i;
            else if(dominoes[i] == 'L') leftposition[i] = -1;
            else leftposition[i] = leftposition[i - 1];
        }
        rightposition[n - 1] = dominoes[n - 1] == 'L' ? n - 1 : -1;
        for(int i = n - 2; i >= 0; i--){
            if(dominoes[i] == 'L') rightposition[i] = i;
            else if(dominoes[i] == 'R') rightposition[i] = -1;
            else rightposition[i] = rightposition[i + 1];
        }
        for(int i = 0; i < n; i++){
            if(leftposition[i] == -1){
                if(rightposition[i] == -1)
                    dominoes[i] = '.';
                else
                    dominoes[i] = 'L';
            }
            else{
                if(rightposition[i] == -1)
                    dominoes[i] = 'R';
                else{
                    if(i - leftposition[i] == rightposition[i] - i)
                        dominoes[i] = '.';
                    else if(i - leftposition[i] > rightposition[i] - i)
                        dominoes[i] = 'L';
                    else
                        dominoes[i] = 'R';
                }
            }
        }
        return dominoes;
    }
};