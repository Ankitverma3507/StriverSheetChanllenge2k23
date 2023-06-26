#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void f(Node* root, int k, int &cnt, int &ans){
    if(root==NULL) return ;

    f(root->right,k,cnt,ans);
    cnt++;
    if(cnt==k){
        ans= root->data;
        return;
    }
    f(root->left, k,cnt,ans);

}
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int cnt=0;
        int ans;
        f(root,k,cnt,ans);
        return ans;
    }
};