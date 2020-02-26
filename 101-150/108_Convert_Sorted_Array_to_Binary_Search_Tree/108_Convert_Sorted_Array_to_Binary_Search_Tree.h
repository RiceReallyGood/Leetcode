#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return NULL;

        int c = (l + r) / 2;
        TreeNode *curr = new TreeNode(nums[c]);
        curr->left = sortedArrayToBST(nums, l, c);
        curr->right = sortedArrayToBST(nums, c + 1, r);
        return curr;
    }
};