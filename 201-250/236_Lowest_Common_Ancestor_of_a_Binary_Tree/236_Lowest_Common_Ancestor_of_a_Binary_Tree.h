#include <vector>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        ppath.clear();
        qpath.clear();
        vector<TreeNode *> path;
        find_p_q_path(root, path, p, q);
        for (int i = 0; i < ppath.size() && i < qpath.size(); i++)
            if (ppath[i] != qpath[i])
                return ppath[i - 1];

        return ppath[0];
    }

private:
    bool find_p_q_path(TreeNode *root, vector<TreeNode *> &path, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return false;

        path.push_back(root);
        if (root == p)
            ppath = path;
        if (root = q)
            qpath = path;

        if (!ppath.empty() && !qpath.empty())
            return true;

        bool found = find_p_q_path(root->left, path, p, q) || find_p_q_path(root->right, path, p, q);

        path.pop_back();
        return found;
    }

    vector<TreeNode *> ppath;
    vector<TreeNode *> qpath;
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        have_p_or_q(root, p, q);
        return res;
    }

private:
    bool have_p_or_q(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return false;

        int left = have_p_or_q(root->left, p, q) ? 1 : 0;
        int right = have_p_or_q(root->right, p, q) ? 1 : 0;
        int mid = (root == p || root == q) ? 1 : 0;

        if (left + mid + right >= 2)
            res = root;

        return (left + right + mid > 0);
    }

    TreeNode *res;
};