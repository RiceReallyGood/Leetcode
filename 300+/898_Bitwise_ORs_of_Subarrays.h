#include <vector>
#include <unordered_set>
using namespace std;

class Solution { //TLE
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int sz = A.size();
        unordered_set<int> ORset;
        for(int i = 0; i < sz; i++){
            int curr = A[i];
            for(int j = i; j < sz; j++){
                curr |= A[j];
                if(ORset.find(curr) == ORset.end())
                    ORset.insert(curr);
            }
        }
        return ORset.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int sz = A.size();
        unordered_set<int> ret;
        unordered_set<int> curr;
        for(int i = 0; i < sz; i++){
            unordered_set<int> temp;
            for(int num : curr)
                temp.insert( num | A[i]);
            temp.insert(A[i]);
            ret.insert(temp.begin(), temp.end());
            swap(curr, temp);
        }
        return ret.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        
        vector<int> B;
        unordered_set<int> S;
        
        for (int a : A)
        {
            B.push_back(a);
            S.insert(a);
            
            for (int i = B.size() - 2; i >= 0 && (B[i] | a) != B[i]; --i)
                S.insert(B[i] |= a);
        }
        
        return S.size();
    }
};