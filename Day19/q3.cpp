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
   TreeNode* t(vector<int>& postorder, vector<int>& inorder, int ip,int jp,int ii,int ji, unordered_map<int,int>&mp){
        if (ip>jp || ii>ji) return NULL;

        TreeNode* root = new TreeNode(postorder[jp]);
        int index = mp[postorder[jp]];
        int leflen = index - ii;
        int rightlen = ji-index;

        root->left = t(postorder,inorder,ip,ip+leflen-1,ii,index-1,mp);
        root->right = t(postorder,inorder,jp-rightlen,jp-1,index+1,ji,mp);
        return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return t(postorder,inorder,0,n-1,0,n-1,mp);
    }
};