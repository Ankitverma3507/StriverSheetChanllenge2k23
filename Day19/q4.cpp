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

bool symmetric(TreeNode* leftroot, TreeNode* rightroot ){
    if(leftroot==NULL or rightroot==NULL )
    return leftroot== rightroot;

    return (leftroot->val== rightroot->val) and symmetric(leftroot->left, rightroot->right) and symmetric(leftroot->right, rightroot->left);
}
    bool isSymmetric(TreeNode* root) {

        if(root==NULL)
        return true;

        return symmetric(root->left, root->right);
        
        TreeNode* leftroot= root->left;
        TreeNode* rightroot= root->right;

        bool isleft= isSymmetric(leftroot);
        bool isright= isSymmetric(rightroot);


        return (leftroot->val==rightroot->val) and isleft and isright; 

        
    }
};