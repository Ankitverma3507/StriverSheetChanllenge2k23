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

class info
{
public:
    int maxi;
    int mini;
    bool isvalid;
    int sum;
};

class Solution
{
public:
    info solve(TreeNode *root, int &maxsum)
    {
        if (root == NULL)
            return {INT_MIN, INT_MAX, true, 0};

        info left = solve(root->left, maxsum);
        info right = solve(root->right, maxsum);

        info currnode;
        currnode.maxi = max(root->val, right.maxi);
        currnode.mini = min(root->val, left.mini);
        currnode.sum = left.sum + right.sum + root->val;

        currnode.isvalid = (left.isvalid and right.isvalid and (root->val > left.maxi and root->val < right.mini));

        // updattion of answer
        if (currnode.isvalid)
        {
            maxsum = max(maxsum, currnode.sum);
        }
        return currnode;
    }
    int maxSumBST(TreeNode *root)
    {
        int maxsum = 0;
        info node = solve(root, maxsum);
        return maxsum;
    }
};