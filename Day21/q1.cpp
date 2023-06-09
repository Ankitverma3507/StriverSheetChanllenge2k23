#include <bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int floor=-1;
    while(root){
        if(root->val==x){
            floor= root->val;
            return floor;
        }

        if(root->val< x){
            floor= root->val;
            root= root->right;
        }

        else
        root= root->left;
    }

    return floor;
}