/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int,multiset<int>>> mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            
            TreeNode *node= it.first;
            int line= it.second.first;
            int lvl= it.second.second;

            mpp[line][lvl].insert(node->val);
            if(node->left){
                q.push({node->left,{line-1, lvl+1}});
            }

            if(node->right){
                q.push({node->right,{line+1, lvl+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p: mpp){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void leftview(Node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    leftview(root->left, lvl + 1, ans);
    leftview(root->right, lvl + 1, ans);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    leftview(root, 0, ans);
    return ans;
}









#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////RIGHT VIEW
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void leftview(Node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    leftview(root->right, lvl + 1, ans);
    leftview(root->left, lvl + 1, ans);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    leftview(root, 0, ans);
    return ans;
}