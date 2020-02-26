#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long num = numerator, den = denominator;
        long rec = num % den;
        if(rec == 0)
            return to_string(num / den);

        ostringstream oss;        
        long ip = num / den;
        if(ip == 0 && ((rec < 0 && denominator > 0) || rec > 0 && denominator < 0))
            oss << "-" << 0;
        else
            oss << ip;
        
        oss << ".";
        long den = denominator;
        rec = rec < 0 ? -rec : rec;
        den = den < 0 ? -den : den;
        unordered_map<int,int> numindex;
        int index = oss.str().length();
        while(rec){
            if(numindex.find(rec) != numindex.end()){
                string ret = oss.str();
                ret.insert(numindex[rec],"("); 
                ret.push_back(')');
                return ret;
            }
            numindex.insert({rec, index++});
            rec *= 10;
            oss << rec / den;
            rec %= den;
        }
        return oss.str();
    }
};