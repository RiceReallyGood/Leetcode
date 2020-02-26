class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *leftbound = root;
        while (true)
        {
            Node *curr = leftbound;

            while (curr && !curr->left && !curr->right)
                curr = curr->next;

            if (!curr)
                break;

            leftbound = curr->left ? curr->left : curr->right;
            Node *nextlevel = leftbound;
            while (curr)
            {
                if (curr->left)
                {
                    nextlevel->next = curr->left;
                    nextlevel = curr->left;
                }
                if (curr->right)
                {
                    nextlevel->next = curr->right;
                    nextlevel = curr->right;
                }
                curr = curr->next;
            }
            nextlevel->next = nullptr;
        }
        return root;
    }
};