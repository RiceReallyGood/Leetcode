#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Binomial.h"
#include <unordered_set>
using namespace std;

int sumNums(int n){
    return n && (n + sumNums(n - 1));
}

int main(void)
{
    string s = "\\\\\\";
    cout << "string: " << s << "\nstring length: " << s.length()  << endl;
}