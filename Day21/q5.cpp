#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BST
{
    stack<TreeNode *> myStack;
    bool reverse = true;

    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            myStack.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BST(TreeNode *root, bool i)
    {
        reverse = i;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }
};
class Solution
{

public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;

        BST l(root, false);
        BST r(root, true);

        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};