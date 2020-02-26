class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x != 0 && x % 10 == 0)
            return false;
        int revert = 0;
        while (x > revert)
        {
            revert *= 10;
            revert += x % 10;
            x /= 10;
        }
        return x == revert || x == revert / 10;
    }
};