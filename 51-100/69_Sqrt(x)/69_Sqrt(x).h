class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1 || x == 0)
            return x;
        int left = 0, right = x;
        int center;
        while (left < right)
        {
            center = (left + right) / 2;
            if (x / center >= center)
                left = center + 1;
            else
                right = center;
        }
        return left - 1;
    }
};