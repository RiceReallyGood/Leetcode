#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        vector<int> threedigits;
        while(num){
            threedigits.push_back(num % 1000);
            num /= 1000;
        }
        string ret;
        for(int i = threedigits.size() - 1; i >= 0; --i){
            if(threedigits[i] == 0)
                continue;
            if(i != threedigits.size() - 1)
                ret += " ";
            ret += tohundred(threedigits[i]);
            ret += thousands[i];
        }
        return ret;
    }

private:
    string tohundred(int num){
        string ret;
        if(num > 99){
            ret += digits[num / 100] + " Hundred";
            num %= 100;
        }
        if(num > 19){
            if(!ret.empty())
                ret += " ";
            ret += dozens[num / 10];
            num %= 10;
        }
        else if(num > 9){
            if(!ret.empty())
                ret += " ";
            ret += teens[num - 10];
            num = 0;
        }
        if(num != 0){
            if(!ret.empty())
                ret += " ";
            ret += digits[num];
        }
        return ret;
    }

    static vector<string> digits;
    static vector<string> teens;
    static vector<string> dozens;
    static vector<string> thousands;
};

vector<string> Solution::digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> Solution::teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                    "Eighteen", "Nineteen"};
vector<string> Solution::dozens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> Solution::thousands = {"", " Thousand", " Million", " Billion"};