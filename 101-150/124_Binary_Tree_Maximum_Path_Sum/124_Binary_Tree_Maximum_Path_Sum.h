#include <algorithm>
using namespace std;

#define NULL nullptr
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
    int maxPathSum(TreeNode *root)
    {
        int maxsum = root->val;
        maxPathFromRoot(root, maxsum);
        return maxsum;
    }

private:
    int maxPathFromRoot(TreeNode *root, int &maxsum)
    {
        if (!root)
            return 0;

        int leftmax = maxPathFromRoot(root->left, maxsum);
        int rightmax = maxPathFromRoot(root->right, maxsum);

        if (leftmax < 0)
        {
            if (rightmax < 0)
            {
                maxsum = max(maxsum, root->val);
                return root->val;
            }
            else
            {
                maxsum = max(maxsum, rightmax + root->val);
                return rightmax + root->val;
            }
        }
        else
        {
            if (rightmax < 0)
            {
                maxsum = max(maxsum, leftmax + root->val);
                return leftmax + root->val;
            }
            else
            {
                maxsum = max(maxsum, leftmax + rightmax + root->val);
                return max(leftmax, rightmax) + root->val;
            }
        }
    }
};