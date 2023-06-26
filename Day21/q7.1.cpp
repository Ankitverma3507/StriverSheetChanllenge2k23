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

class info
{
    public:
    int mini; 
    int maxi;
    bool isvalid;
    int size;
};


info solve(TreeNode<int>* root, int &maxsize){
    if(root==NULL){
        return {INT_MAX, INT_MIN, true,0};
    }

    info left= solve(root->left, maxsize);
    info right= solve(root->right, maxsize);

    info currnode;
    currnode.size= left.size+ right.size+1;
    currnode.maxi= max(root->data, right.maxi);
    currnode.mini= min(root->data, left.mini);
    

    //now to update currnode is valid we have to check the conditns
    if(left.isvalid and right.isvalid and (root->data >left.maxi) and (root->data< right.mini))
    currnode.isvalid= true;
    else
    currnode.isvalid= false;
 

    //updation of answer
    if(currnode.isvalid)
    maxsize= max(maxsize, currnode.size);
    return currnode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize=0;//this is the size which we have to return as a answer
    info temp= solve(root, maxSize);
    return maxSize;

}























