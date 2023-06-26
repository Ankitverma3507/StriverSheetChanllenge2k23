#include <bits/stdc++.h>
using namespace std;
 

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head){
    if(root==NULL) return ;

    solve(root->left,prev,head);
    if(prev==NULL) head= root;
    else
    {
        root->left= prev;
        prev->right= root;
    }
    prev= root;

    solve(root->right,prev,head);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev=NULL;
    BinaryTreeNode<int>* head=NULL;
    solve(root, prev, head);
    return head;
}