#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target)
                return {i + 1, j + 1};
            if(sum < target)
                i++;
            else
                j--;
        }
        return {0, 0};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = upperbound(numbers, target - numbers[i], i + 1, numbers.size()) - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target)
                return {i + 1 , j + 1};
            if(sum < target)
                i = lowerbound(numbers, target - numbers[j], i + 1, j - 1);
            else
                j = upperbound(numbers, target - numbers[i], i + 1, j) - 1;
        }
        return {0, 0};
    }

private:
    int upperbound(vector<int>& numbers, int target, int l, int r){
        while(l < r){
            int c= l + (r - l) / 2;
            if(numbers[c] <= target)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
    int lowerbound(vector<int>& numbers, int target, int l, int r){
        while(l < r){
            int c= l + (r - l) / 2;
            if(numbers[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
};