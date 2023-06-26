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
class Solution
{
public:
    TreeNode *f(vector<int> &arr, int &i, int upperbound)
    {
        if (i == arr.size() or arr[i] > upperbound)
            return NULL;

        TreeNode *root = new TreeNode(arr[i]);
        i++;
        root->left = f(arr, i, root->val);
        root->right = f(arr, i, upperbound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return f(preorder, i, INT_MAX);
    }
};