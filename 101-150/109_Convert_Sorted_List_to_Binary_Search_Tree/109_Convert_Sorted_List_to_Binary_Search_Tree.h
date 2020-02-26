#define NULL nullptr
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        listnode = head;
        int sz = 0;
        ListNode *p = head;
        while (p)
        {
            ++sz;
            p = p->next;
        }
        return sortedListToBST(0, sz);
    }

private:
    TreeNode *sortedListToBST(int l, int r)
    {
        if (l == r)
            return nullptr;

        int mid = (l + r) / 2;
        TreeNode *lefttree = sortedListToBST(l, mid);
        TreeNode *root = new TreeNode(listnode->val);
        listnode = listnode->next;
        root->left = lefttree;
        root->right = sortedListToBST(mid + 1, r);

        return root;
    }

    ListNode *listnode;
};