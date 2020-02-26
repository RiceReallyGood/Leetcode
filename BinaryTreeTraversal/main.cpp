#include "BinaryTreeTraversal.h"

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    node2->left = node1;
    node2->right = node3;
    node6->left = node5;
    node6->right = node7;

    node4->left = node2;
    node4->right = node6;

    PreOrderRecursive(node4);
    cout << endl;
    PreOrderIterative(node4);
    cout << endl;
    InOrderRecursive(node4);
    cout << endl;
    InOrderIterative(node4);
    cout << endl;
    PostOrderRecursive(node4);
    cout << endl;
    PostOrderIterative(node4);
    cout << endl;
}