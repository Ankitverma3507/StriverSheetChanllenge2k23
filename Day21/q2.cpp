#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };


int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int floor=-1;
    while(root){
        if(root->data==x){
            floor= root->data;
            return floor;
        }

        if(root->data< x){
            root= root->right;
        }

        else
       { floor= root->data;
        root= root->left;}
    }

    return floor;
}