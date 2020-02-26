#define NULL nullptr
#include <climits>
#include <algorithm>
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *bugnode1 = NULL, *bugnode2 = NULL;
        //Morris Traversal
        int lastval = INT_MIN;
        TreeNode *p = root;
        TreeNode *lastp = NULL;
        while (p)
        {
            if (!p->left)
            {
                if (p->val < lastval)
                {
                    bugnode1 = (bugnode1 == NULL ? lastp : bugnode1);
                    bugnode2 = p;
                }
                lastval = p->val;
                lastp = p;
                p = p->right;
            }
            else
            {
                TreeNode *prev = PrevNode(p);
                if (!prev->right)
                {
                    prev->right = p;
                    p = p->left;
                }
                else
                {
                    prev->right = NULL;
                    if (p->val < lastval)
                    {
                        bugnode1 = (bugnode1 == NULL ? lastp : bugnode1);
                        bugnode2 = p;
                    }
                    lastval = p->val;
                    lastp = p;
                    p = p->right;
                }
            }
        }

        std::swap(bugnode1->val, bugnode2->val);
    }

    TreeNode *PrevNode(TreeNode *root)
    {
        TreeNode *p = root->left;
        while (p->right && p->right != root)
            p = p->right;
        return p;
    }
};