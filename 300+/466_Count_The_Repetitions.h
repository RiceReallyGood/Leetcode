#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<int> matchtotal(l2, 0);
        vector<int> matchchar(l2, 0);
        vector<int> rest(l2, -1);
        int nums1 = 0;
        rest[0] = 0;
        int j = 0;
        int match = 0;
        while(true){
            nums1++;
            for(int i = 0; i < l1; i++){
                if(s1[i] == s2[j]){
                    j++;
                    if(j == l2){
                        match++;
                        j = 0;
                    }
                }
            }
            if(rest[j] != -1)
                break;
            matchtotal[nums1] = match;
            matchchar[nums1] = j;
            rest[j] = nums1;    
        }
        if(n1 < nums1)
            return matchtotal[n1] / n2;
        int cycle1 = nums1 - rest[j];
        int cycle2 = match - matchtotal[rest[j]];
        int nums2 = (n1 - rest[j]) / cycle1 * cycle2 + matchtotal[(n1 - rest[j]) % cycle1 + rest[j]];
        return nums2 / n2;
    }
};