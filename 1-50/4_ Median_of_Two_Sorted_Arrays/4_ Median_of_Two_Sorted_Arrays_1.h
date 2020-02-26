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
        int m = nums1.size(), n = nums2.size();
        if (m == 0)
        {
            if (n % 2 == 0)
                return double(nums2[n / 2 - 1] + nums2[n / 2]) / 2.;
            else
                return double(nums2[n / 2]);
        }
        else if (n == 1)
        {
            return double(nums1[0] + nums2[0]) / 2.;
        }
        int lowerbound = 0, upperbound = m;
        int i = 0, j = (m + n + 1) / 2;
        if (nums1[i] >= nums2[j - 1])
        {
            if (j == n)
            {
                if ((m + n) % 2 == 0)
                    return double(nums1[i] + nums2[j - 1]) / 2;
                else
                    return double(nums2[j - 1]);
            }
            else
            {
                if ((m + n) % 2 == 0)
                    return double(nums2[j - 1] + min(nums1[i], nums2[j])) / 2;
                else
                    return double(nums2[j - 1]);
            }
        }
        else
        {
            lowerbound = i + 1;
        }
        while (lowerbound != upperbound)
        {
            i = (lowerbound + upperbound) / 2;
            j = (m + n + 1) / 2 - i;
            if (nums1[i] < nums2[j - 1])
                lowerbound = i + 1;
            else if (nums1[i - 1] > nums2[j])
                upperbound = i - 1;
            else
                lowerbound = upperbound = i;
        }
        i = upperbound;
        j = (m + n + 1) / 2 - i;
        if (i == m)
        {
            if (j == 0)
            {
                if ((n + m) % 2 == 0)
                    return double(nums1[i - 1] + nums2[j]) / 2.;
                else
                    return double(nums1[i - 1]);
            }
            if ((n + m) % 2 == 0)
                return double(max(nums1[i - 1], nums2[j - 1]) + nums2[j]) / 2.;
            else
                return double(max(nums1[i - 1], nums2[j - 1]));
        }
        if ((n + m) % 2 == 0)
            return double(max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) / 2.;
        else
            return double(max(nums1[i - 1], nums2[j - 1]));
        return 0;
    }
};