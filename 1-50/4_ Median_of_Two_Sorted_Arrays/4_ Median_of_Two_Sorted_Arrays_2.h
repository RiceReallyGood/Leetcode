#include <vector>
using namespace std;
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }
        vector<int> &A = nums1, &B = nums2;
        int m = A.size(), n = B.size();
        int half = (m + n + 1) / 2;
        int i = 0, j = half;
        int lowerbound = 0, upperbound = m;
        while (lowerbound <= upperbound)
        {
            i = (lowerbound + upperbound) / 2;
            j = half - i;
            if (i < upperbound && A[i] < B[j - 1])
                lowerbound = i + 1;
            else if (i > lowerbound && A[i - 1] > B[j])
                upperbound = i - 1;
            else
            {
                int leftmax = 0;
                if (i == 0)
                    leftmax = B[j - 1];
                else if (j == 0)
                    leftmax = A[i - 1];
                else
                    leftmax = max(A[i - 1], B[j - 1]);
                if ((m + n) % 2 == 1)
                    return leftmax;

                int rightmin = 0;
                if (i == m)
                    rightmin = B[j];
                else if (j == n)
                    rightmin = A[i];
                else
                    rightmin = min(A[i], B[j]);
                return double(leftmax + rightmin) / 2.;
            }
        }
        return 0;
    }
};