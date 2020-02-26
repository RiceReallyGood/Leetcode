#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = 1 << 16;
        vector<int> singlet(n, 0), doublet(n, 0);
        int triplet = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < n; j++)
                if(doublet[j] != 0 && (j & A[i]) == 0)
                    triplet += doublet[j];
            for(int j = 0; j < n; j++){
                if(singlet[j] != 0)
                    doublet[j & A[i]] += singlet[j];
            }
            singlet[A[i]]++;
        }
        return singlet[0] + 6 * doublet[0] + 6 * triplet;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> singlet, doublet;
        int triplet = 0;
        for(int i = 0; i < A.size(); i++){
            for(auto p : doublet){
                if((p.first & A[i]) == 0)
                    triplet += p.second;
            }

            for(auto p : singlet)
                doublet[p.first & A[i]] += p.second;
            
            singlet[A[i]]++;
        }
        return singlet[0] + 6 * doublet[0] + 6 * triplet;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int ret = 0;
        int n = A.size();
        for(int i = 0; i < n; i++)
            if(A[i] == 0)
                ret++;
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if((A[i] & A[j]) == 0){
                    ret += 6;
                }
            }
        }

        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    if((A[i] & A[j] & A[k]) == 0){
                        ret += 6;
                    }
                }
            }
        }
        
        return ret;
    }
};


class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = 1 << 16;
        vector<int> doublet(n, 0);
        for(int a : A){
            for(int b : A){
                doublet[a & b]++;
            }
        }
        int ret = 0;
        for(int a : A){
            for(int i = 0; i < n; i++){
                int k = i & a;
                if(k == 0)
                    ret += doublet[i];
                else
                    i += k - 1;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = 1 << 16;
        vector<int> doublet(n, 0);
        for(int a : A){
            for(int b : A){
                doublet[a & b]++;
            }
        }

        int ret = 0;
        for(int a : A){
            int mask = (~a) & (n - 1);
            for(int i = mask; i ; i = (i - 1) & mask){
                ret += doublet[i];
            }
            ret += doublet[0];
        }
        return ret;
    }
};