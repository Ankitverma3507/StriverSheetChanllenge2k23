#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    int pre = -1;
    int suc = -1;

    // here we have find the given key so that we can find pred and succ after that
    while (root->data != x)
    {

        if (x > root->data)
        {
            pre = root->data;
            root = root->right;
        }
        else
        {
            suc = root->data;
            root = root->left;
        }
    }

    BinaryTreeNode<int> *leftnode = root->left;
    while (leftnode)
    {
        pre = leftnode->data;
        leftnode = leftnode->right; // as we want max fron left subtree thats why we are itterating on right;
    }

    BinaryTreeNode<int> *rightnode = root->right;
    while (rightnode)
    {
        suc = rightnode->data;
        rightnode = rightnode->left; // as we want min fron right subtree thats why we are itterating on left;
    }

    pair<int, int> ans;
    ans = {pre, suc};
    return ans;
}
