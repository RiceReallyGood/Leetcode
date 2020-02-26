bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int c;
        while(l != r){
            c = l + (r - l) / 2;
            if(isBadVersion(c))
                r = c;
            else
                l = c + 1;
        }
        return l;
    }
};