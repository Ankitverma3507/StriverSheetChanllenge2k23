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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        int curr= root->val;

        if(p->val >curr and q->val> curr){
            return lowestCommonAncestor(root->right, p, q);
        }

        else if(p->val<curr and q->val <curr){
            return lowestCommonAncestor(root->left, p,q);
        }
        return root;

    }
};