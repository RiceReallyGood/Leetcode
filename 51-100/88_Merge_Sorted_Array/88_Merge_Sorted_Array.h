#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        int sz = m + n;
        nums1.resize(sz);
        for (int i = m - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];

        int i = n, j = 0;
        int filled = 0;
        while (j < n && i < sz)
        {
            if (nums1[i] < nums2[j])
                nums1[filled++] = nums1[i++];
            else
                nums1[filled++] = nums2[j++];
        }

        while (j < n)
            nums1[filled++] = nums2[j++];
    }
};