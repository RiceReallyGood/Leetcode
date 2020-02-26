using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        int sign = x < 0 ? -1 : 1;
        return sign * reverse_unsigned(sign * x);
    }

  private:
    int reverse_unsigned(int x)
    {
        int ret = 0;
        while (x)
        {
            if (ret > 214748364)
                return 0;
            else if (ret == 214748364 && x == 1)
                return 2147483641;
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};