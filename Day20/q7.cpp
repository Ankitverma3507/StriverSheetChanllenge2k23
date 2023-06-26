#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int x)
    {
        // Your code goes here
        while(root != NULL){
            if(root->key==x) break;
            else if(x> root->key){
                pre= root;
                root= root->right;
                
            }
            else{
                suc= root;
                root= root->left;
            }
        }
    }
};