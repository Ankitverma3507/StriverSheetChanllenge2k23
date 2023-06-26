#include <bits/stdc++.h>
using namespace std;
///////////////////////////////// Recursive approach
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        // code here
        if (node == NULL)
            return;

        Node *right = node->right;
        node->right = node->left;
        node->left = right;

        mirror(node->left);
        mirror(node->right);
    }
};