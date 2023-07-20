#include <bits/stdc++.h>
using namespace std;
template <typename T> 
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };




void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.

    if (root==NULL) return;

    int childsum=0;
    if(root->left) childsum+= root->left->data;
    if(root->right) childsum+= root->right->data;
    
    if(childsum>= root->data) root->data= childsum;

    else{
        if(root->left) root->left->data= root->data;
        else if(root->right) root->right->data= root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);

    int total=0;
    if(root->left) total+= root->left->data;
    if(root->right) total+= root->right->data;
    if(root->left or root->right) root->data= total;
}  









  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };









