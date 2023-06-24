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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q){
            return root;
        }

        TreeNode* leftnode= lowestCommonAncestor(root->left, p,q);
        TreeNode* rightnode= lowestCommonAncestor(root->right, p,q);

        if(leftnode==NULL) return rightnode;

        else if(rightnode==NULL) return leftnode;

        else{
            return root;
        }


    }
};