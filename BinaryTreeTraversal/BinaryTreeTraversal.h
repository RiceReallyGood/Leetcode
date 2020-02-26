#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visit(TreeNode *node)
{
    // Do some thing here...
    std::cout << node->val << " ";
}

void PreOrderRecursive(TreeNode *root)
{
    if (!root)
        return;

    visit(root);
    PreOrderRecursive(root->left);
    PreOrderRecursive(root->right);
}

void InOrderRecursive(TreeNode *root)
{
    if (!root)
        return;

    InOrderRecursive(root->left);
    visit(root);
    InOrderRecursive(root->right);
}

void PostOrderRecursive(TreeNode *root)
{
    if (!root)
        return;

    PostOrderRecursive(root->left);
    PostOrderRecursive(root->right);
    visit(root);
}

void PreOrderIterative(TreeNode *root)
{
    if (!root)
        return;

    stack<TreeNode *> nodestack;
    nodestack.push(root);

    while (!nodestack.empty())
    {
        TreeNode *p = nodestack.top();
        nodestack.pop();
        visit(p);
        if (p->right)
            nodestack.push(p->right);
        if (p->left)
            nodestack.push(p->left);
    }
}

void InOrderIterative(TreeNode *root)
{
    TreeNode *p = root;
    stack<TreeNode *> nodestack;
    while (!nodestack.empty() || p)
    {
        while (p)
        {
            nodestack.push(p);
            p = p->left;
        }
        p = nodestack.top();
        nodestack.pop();
        visit(p);
        p = p->right;
    }
}

void PostOrderIterative(TreeNode *root)
{
    TreeNode *p = root;
    stack<pair<TreeNode *, bool>> nodestack;
    while (!nodestack.empty() || p)
    {
        while (p)
        {
            nodestack.push({p, false});
            p = p->left;
        }
        auto curr = nodestack.top();
        p = curr.first;
        nodestack.pop();
        if (curr.second == true)
        {
            visit(p);
            p = NULL;
        }
        else
        {
            nodestack.push({p, true});
            p = p->right;
        }
    }
}