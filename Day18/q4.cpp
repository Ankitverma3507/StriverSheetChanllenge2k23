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
    bool isBalanced(TreeNode* root) {
        if(height(root) ==-1) return false;
        else
        return true;
    }

    int height(TreeNode* root){
        if(root== NULL) return 0;

        int lh= height(root->left);
        int rh= height(root->right);

        if(lh ==-1 or rh==-1) return -1;
        if(abs(rh-lh)>1) return -1;

        return 1+ max(lh,rh);
    }
};