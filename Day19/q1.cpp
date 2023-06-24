#include <bits/stdc++.h>
using namespace std;
///////////////////////////////// optimised app
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

    int f(TreeNode* root, int &sum){
        if(root==NULL) return 0;

        int leftmaxpathsum= max(0,f(root->left, sum));
        int rightmaxpathsum= max(0,f(root->right, sum));

        sum= max(sum, leftmaxpathsum+rightmaxpathsum+ root->val);
        return max(leftmaxpathsum, rightmaxpathsum) + root->val;


    }
    int maxPathSum(TreeNode* root) {
        int sum= INT_MIN;
         int temp= f(root,sum);
         return sum;
    }
};