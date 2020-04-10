#include <iostream>
#include "Manacher.h"
using namespace std;

int main(){
    string s = "aaaa";
    Manacher m(s);
    cout << m.longestPalindromeSubstring() << endl;
    cout << m.lengthoflongestPalindromeSubstring() << endl;
    cout << m.PalindromeSubstringCount() << endl;
}