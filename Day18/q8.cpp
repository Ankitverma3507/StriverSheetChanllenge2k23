#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


bool isLeaf(TreeNode<int>* root){
    if(root->left==NULL and root->right==NULL) return true;
    else
    return false;
}

void addleftbound(TreeNode<int>* root,vector<int> &ans ){
     TreeNode<int>* curr= root->left;
     while(curr){
         if(!isLeaf(curr))
         ans.push_back(curr->data);
         if(curr->left) curr= curr->left;
         else
         curr= curr->right;
     }
}


void addrightbound(TreeNode<int>* root,vector<int> &ans){
    TreeNode<int>*curr= root->right;
    vector<int> temp;//as we want to store rigth bound inreverse order
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr= curr->right;
        else
        curr= curr->left;
    }

    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

void addleafnode(TreeNode<int>* root,vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left) addleafnode(root->left, ans);
    if(root->right) addleafnode(root->right, ans);
    
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    addleftbound(root,ans);
    addleafnode(root,ans);
    addrightbound(root,ans);
    return ans;
}