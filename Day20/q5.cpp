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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return f(LONG_MIN, LONG_MAX, root);
    }

    bool f(long minval, long maxval, TreeNode* root)
    {
        if(root==NULL) return true;
        if(root->val >=maxval or root->val<= minval) return false;

        return f(minval, root->val,root->left) and f(root->val, maxval, root->right);
    }
};