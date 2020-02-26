#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        vector<int> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<char> nums;
        for (int i = 0; i < n; i++)
            nums.push_back(i + '1');
        int order;
        while (k % factorials[n - 1])
        {
            order = k / factorials[n - 1];
            s.push_back(nums[order]);
            nums.erase(nums.begin() + order);
            k %= factorials[n - 1];
            n--;
        }
        order = k / factorials[n - 1] - 1;
        s.push_back(nums[order]);
        nums.erase(nums.begin() + order);
        while (!nums.empty())
        {
            s.push_back(nums.back());
            nums.pop_back();
        }
        return s;
    }
};