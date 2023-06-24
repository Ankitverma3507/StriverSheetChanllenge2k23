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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright= true;

        while(!q.empty()){
            int size= q.size();
            vector<int> temp(size);

            for(int i=0; i<size; i++){
                TreeNode* node= q.front();
                q.pop();
                
                int ind= lefttoright? i: size-i-1;

                temp[ind]= node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
                lefttoright= !lefttoright;
                ans.push_back(temp);
        }

        return ans;
    }
};