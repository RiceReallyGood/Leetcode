class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int last1 = 1, last2 = 1;
        int curr;
        for (int i = 2; i <= n; i++)
        {
            curr = last1 + last2;
            last2 = last1;
            last1 = curr;
        }
        return curr;
    }
};