#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;

        queue<pair<Node*, int>>q;
        map<int, Node*>mpp;
        q.push({root,1});

        while(!q.empty()){
            auto it= q.front();
            q.pop();

            Node * node= it.first;
            int ind= it.second;
            mpp[ind]= node;
            if(node->right and node->left){
                q.push({node->left, 2*ind});
                q.push({node->right, 2*ind+1});
            }
        }

        int i=1;// this i is checking that is this node is rightmost node or not because next pointer of rightmost node will point to null
        for(auto it: mpp){
            if(it.first==i){
                it.second->next=NULL;
                i= 2*i +1;
            }
            else{
                it.second->next= mpp[it.first+1];
            }
        }
        return root;
    }
    
};