class Solution
{
public:
    int climbStairs(int n)
    {
        return Fibnacci(n + 1);
    }

    int Fibnacci(int n)
    {
        Mat22 fib(1, 1, 1, 0);
        return FastPow(fib, n - 1).m11;
    }

    class Mat22
    {
    public:
        Mat22() = default;
        Mat22(const int &a, const int &b, const int &c, const int &d) : m11(a), m12(b), m21(c), m22(d) {}
        int m11, m12, m21, m22;
        Mat22 operator*(const Mat22 &rhs) const
        {
            return Mat22{
                m11 * rhs.m11 + m12 * rhs.m21, m11 * rhs.m12 + m12 * rhs.m22,
                m21 * rhs.m11 + m22 * rhs.m21, m21 * rhs.m12 + m22 * rhs.m22};
        }
        Mat22 operator*=(const Mat22 &rhs)
        {
            *this = *this * rhs;
            return *this;
        }
    };

    Mat22 FastPow(const Mat22 &mat, int n)
    {
        if (n == 0)
            return {1, 0, 0, 1};
        if (n == 1)
            return mat;
        if (n & 1)
            return mat * FastPow(mat * mat, n / 2);
        else
            return FastPow(mat * mat, n / 2);
    }
};